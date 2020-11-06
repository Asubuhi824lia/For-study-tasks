/********************************************************************************
** Form generated from reading UI file 'auth.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTH_H
#define UI_AUTH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_auth
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QTextEdit *textEdit;

    void setupUi(QWidget *auth)
    {
        if (auth->objectName().isEmpty())
            auth->setObjectName(QStringLiteral("auth"));
        auth->resize(555, 248);
        horizontalLayout_2 = new QHBoxLayout(auth);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(auth);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8("../\320\230\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217/\320\233\320\276\320\263\320\276\320\242\320\270\320\277.png")));

        horizontalLayout->addWidget(label);

        textEdit = new QTextEdit(auth);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        horizontalLayout->addWidget(textEdit);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(auth);

        QMetaObject::connectSlotsByName(auth);
    } // setupUi

    void retranslateUi(QWidget *auth)
    {
        auth->setWindowTitle(QApplication::translate("auth", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276\320\261 \320\260\320\262\321\202\320\276\321\200\320\260\321\205", Q_NULLPTR));
        label->setText(QString());
        textEdit->setHtml(QApplication::translate("auth", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:20pt; color:#ef2929;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt; color:#ef2929;\">\320\230</span><span style=\" font-size:20pt; color:#8ae234;\">\320\275\321\204\320\276</span><span style=\" font-size"
                        ":20pt; color:#9ae89d;\">\321\200\320\274\320\260\321\206</span><span style=\" font-size:20pt; color:#f7a9e1;\">\320\270\321\217 \320\276\320\261</span><span style=\" font-size:20pt; color:#ad7fa8;\"> </span><span style=\" font-size:20pt; color:#729fcf;\">\320\260\320\262\321\202</span><span style=\" font-size:20pt; color:#bce3ff;\">\320\276\321\200\320\260\321\205</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class auth: public Ui_auth {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTH_H
