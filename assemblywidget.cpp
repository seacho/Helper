#include "assemblywidget.h"
#include "qlabel.h"
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include "mainwidget.h"
#include <QComboBox>
#include <QRegularExpression>
#include <capstone/capstone.h>

#define ARCH_LIST(_) \
    _(HELP_X86,     "x86",       CS_ARCH_X86,   KS_ARCH_X86)       \
    _(HELP_X86_64,  "x86_64",    CS_ARCH_X86,   KS_ARCH_X86)       \
    _(HELP_ARM,     "ARM",       CS_ARCH_ARM,   KS_ARCH_ARM)       \
    _(HELP_AARCH64, "AARCH64",   CS_ARCH_AARCH64, KS_ARCH_ARM64)     \
    _(HELP_PPC32,   "PowerPC32", CS_ARCH_PPC,   KS_ARCH_PPC)       \
    _(HELP_PPC64,   "PowerPC64", CS_ARCH_PPC,   KS_ARCH_PPC)       \
    _(HELP_MIPS32,  "MIPS32",    CS_ARCH_MIPS,  KS_ARCH_MIPS)      \
    _(HELP_MIPS64,  "MIPS64",    CS_ARCH_MIPS,  KS_ARCH_MIPS)


enum HELPARCH {
#define X(name, text, csArch, ksArch) name,
    ARCH_LIST(X)
#undef X
};

static const QVector<QString> vecArchName = []{
    QVector<QString> v;
#define X(name, text, csArch, ksArch) \
    v.append((text));
    ARCH_LIST(X)
#undef X
    return v;
}();

static constexpr int csArch[] = {
#define X(name, text, csArch, ksArch) csArch,
    ARCH_LIST(X)
#undef X
};

static constexpr int ksArch[] = {
#define X(name, text, csArch, ksArch) ksArch,
    ARCH_LIST(X)
#undef X
};

AssemblyWidget::AssemblyWidget(QWidget *parent)
    : QWidget{parent}
{
    ksEng = nullptr;
    QVBoxLayout *layout = new QVBoxLayout(this);


    QHBoxLayout *labelLayout = new QHBoxLayout(this);
    labelLayout->setAlignment(Qt::AlignLeft);
    QLabel *titleLabel = new QLabel("Assemble Code", this);
    titleLabel->setStyleSheet("font-size: 18pt; font-weight: bold;");
    labelLayout->addWidget(titleLabel);

    QComboBox *archSelector = new QComboBox();
    labelLayout->addWidget(archSelector);
    layout->addLayout(labelLayout);
    for (const auto& i: vecArchName)
    {
        archSelector->addItem(i);
    }

    QBoxLayout *contextLayout = new QBoxLayout(QBoxLayout::LeftToRight ,this);

    layout->addLayout(contextLayout);

//    QLabel *inputLabel = new QLabel("Enter Assembly Code:", this);
//    contextLayout->addWidget(inputLabel);

    assemblyInput = new QTextEdit(this);
    assemblyInput->setPlaceholderText("Write your assembly code here...");
    contextLayout->addWidget(assemblyInput);

    QBoxLayout *buttonLayout = new QBoxLayout(QBoxLayout::TopToBottom ,this);
    contextLayout->addLayout(buttonLayout);
    QPushButton *assembleButton = new QPushButton("Assembly->", this);
    buttonLayout->addWidget(assembleButton);
    QPushButton *disassembleButton = new QPushButton("<-Disassembly", this);
    buttonLayout->addWidget(disassembleButton);

//    QLabel *outputLabel = new QLabel("Output:", this);
//    contextLayout->addWidget(outputLabel);

    outputDisplay = new QTextEdit(this);
    contextLayout->addWidget(outputDisplay);

    // You would connect signals from assembleButton here to perform the assembly logic
    connect(assembleButton, &QPushButton::clicked, this, &AssemblyWidget::setBinaryTextEdit);
    connect(disassembleButton, &QPushButton::clicked, this, &AssemblyWidget::setAssemblyTextEdit);
    //connect(archSelector, &QComboBox::currentIndexChanged, this, &AssemblyWidget::setCurArch);
    connect(archSelector, &QComboBox::activated, this, &AssemblyWidget::setCurArch);
    emit archSelector->activated(archSelector->currentIndex());

}

//QString insertSpacesEveryTwo(const QString &input) {
//    QString result;
//    result.reserve(input.size() + input.size() / 2);  // 预留空间
//    for (int i = 0; i < input.size(); i += 2) {
//        result += input.mid(i, 2);
//        if (i + 2 < input.size())
//            result += ' ';
//    }
//    return result;
//}

void AssemblyWidget::setBinaryTextEdit()
{
    QString plain = assemblyInput->toPlainText();
    std::string str = plain.toStdString();
    const char *assembly = str.c_str();
    unsigned char *encode;
    size_t size, count;

    int err = ks_asm(ksEng, assembly, 0, &encode, &size, &count);
    if (err == KS_ERR_OK) {
        QByteArray arr = QByteArray::fromRawData(reinterpret_cast<const char*>(encode), size);
        QString hex = arr.toHex().toUpper();
        QRegularExpression re("(.{2})");
        hex = hex.replace(re, "\\1 ").trimmed();
        outputDisplay->setPlainText(hex);
    } else {
        //outputDisplay->setTextColor(Qt::red);
        QString errinfo = "<span style=\"color:red;\">";
        errinfo += ks_strerror(ks_errno(ksEng));
        errinfo += "</span>";
        outputDisplay->setHtml(errinfo);

    }
}

void AssemblyWidget::setAssemblyTextEdit()
{
    QString hexStr = outputDisplay->toPlainText();
    hexStr = hexStr.remove(' ');  // 去掉空格
    QByteArray byteArray = QByteArray::fromHex(hexStr.toUtf8());
    const uint8_t *code = reinterpret_cast<uint8_t*>(byteArray.data());

    size_t size = byteArray.length(), count;
    cs_insn* insn;
    cs_option(csEng, CS_OPT_DETAIL, CS_OPT_ON);

    count = cs_disasm(csEng, code, size, 0, 0, &insn);
    if (count > 0) {
        QString ass;
        for (size_t i = 0; i < count; i++) {
            //ass += "0x";
            //ass += QString::number(insn[i].address, 16).toUpper();
            //ass +=": ";
            ass += insn[i].mnemonic;
            ass += " ";
            ass += insn[i].op_str;
            ass += "\n";
        }
        assemblyInput->setPlainText(ass);
    } else {
        //outputDisplay->setTextColor(Qt::red);
        //outputDisplay->setTextColor(Qt::red);
        QString errinfo = "<span style=\"color:red;\">";
        errinfo += cs_strerror(cs_errno(csEng));
        errinfo += "</span>";
        assemblyInput->setHtml(errinfo);
    }
    cs_free(insn, count);
}

void AssemblyWidget::setCurArch(int indexArch)
{
    curArch = indexArch;
    ks_close(ksEng);
    int ksmode;
    switch(curArch){
    case HELP_X86:
        ksmode = KS_MODE_32;
        break;
    case HELP_X86_64:
        ksmode = KS_MODE_64;
        break;
    case HELP_ARM:
        ksmode = KS_MODE_ARM;
        break;
    case HELP_AARCH64:
        ksmode = KS_MODE_LITTLE_ENDIAN;
        break;
    case HELP_PPC32:
        ksmode = KS_MODE_PPC32 | KS_MODE_BIG_ENDIAN;
        break;
    case HELP_PPC64:
        ksmode = KS_MODE_PPC64;
        break;
    case HELP_MIPS32:
        ksmode = KS_MODE_MIPS32;
        break;
    case HELP_MIPS64:
        ksmode = KS_MODE_MIPS64;
        break;
    }

    ks_err err = ks_open((ks_arch)ksArch[curArch], ksmode, &ksEng);
    if (err != KS_ERR_OK)
    {
        assert(0);
    }
    // capstone
    cs_close(&csEng);
    int csmode;
    switch(curArch){
    case HELP_X86:
        csmode = CS_MODE_32;
        break;
    case HELP_X86_64:
        csmode = CS_MODE_64;
        break;
    case HELP_ARM:
        csmode = CS_MODE_ARM;
        break;
    case HELP_AARCH64:
        csmode = CS_MODE_LITTLE_ENDIAN;
        break;
    case HELP_PPC32:
        csmode = CS_MODE_32 | CS_MODE_BIG_ENDIAN;
        break;
    case HELP_PPC64:
        csmode = CS_MODE_64;
        break;
    case HELP_MIPS32:
        csmode = CS_MODE_MIPS32;
        break;
    case HELP_MIPS64:
        csmode = CS_MODE_MIPS64;
        break;
    }

    cs_err cserr = cs_open((cs_arch)csArch[curArch], (cs_mode)csmode, &csEng);
    if (cserr != CS_ERR_OK)
    {
        assert(0);
    }
}

QWidget* registerAssemblyWidget()
{
    return new AssemblyWidget();
}
toolMetaInfo gAssemblyWidget(
    "Assembly",
    registerAssemblyWidget
    );


