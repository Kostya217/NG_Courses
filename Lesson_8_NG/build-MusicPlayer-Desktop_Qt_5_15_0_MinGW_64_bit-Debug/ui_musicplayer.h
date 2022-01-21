/********************************************************************************
** Form generated from reading UI file 'musicplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICPLAYER_H
#define UI_MUSICPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MusicPlayer
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *l_songName;
    QPushButton *b_find;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QPushButton *b_backward;
    QPushButton *b_playPause;
    QPushButton *b_forward;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_2;
    QSlider *s_volume;
    QLabel *label;
    QPushButton *b_close;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MusicPlayer)
    {
        if (MusicPlayer->objectName().isEmpty())
            MusicPlayer->setObjectName(QString::fromUtf8("MusicPlayer"));
        MusicPlayer->resize(548, 237);
        centralwidget = new QWidget(MusicPlayer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        l_songName = new QLineEdit(centralwidget);
        l_songName->setObjectName(QString::fromUtf8("l_songName"));

        horizontalLayout_2->addWidget(l_songName);

        b_find = new QPushButton(centralwidget);
        b_find->setObjectName(QString::fromUtf8("b_find"));

        horizontalLayout_2->addWidget(b_find);


        verticalLayout->addLayout(horizontalLayout_2);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        b_backward = new QPushButton(centralwidget);
        b_backward->setObjectName(QString::fromUtf8("b_backward"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(60);
        sizePolicy.setVerticalStretch(60);
        sizePolicy.setHeightForWidth(b_backward->sizePolicy().hasHeightForWidth());
        b_backward->setSizePolicy(sizePolicy);
        b_backward->setMinimumSize(QSize(60, 60));
        b_backward->setMaximumSize(QSize(60, 60));

        horizontalLayout->addWidget(b_backward);

        b_playPause = new QPushButton(centralwidget);
        b_playPause->setObjectName(QString::fromUtf8("b_playPause"));
        sizePolicy.setHeightForWidth(b_playPause->sizePolicy().hasHeightForWidth());
        b_playPause->setSizePolicy(sizePolicy);
        b_playPause->setMinimumSize(QSize(60, 60));
        b_playPause->setMaximumSize(QSize(60, 60));

        horizontalLayout->addWidget(b_playPause);

        b_forward = new QPushButton(centralwidget);
        b_forward->setObjectName(QString::fromUtf8("b_forward"));
        sizePolicy.setHeightForWidth(b_forward->sizePolicy().hasHeightForWidth());
        b_forward->setSizePolicy(sizePolicy);
        b_forward->setMinimumSize(QSize(60, 60));
        b_forward->setMaximumSize(QSize(60, 60));

        horizontalLayout->addWidget(b_forward);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        s_volume = new QSlider(centralwidget);
        s_volume->setObjectName(QString::fromUtf8("s_volume"));
        s_volume->setOrientation(Qt::Vertical);

        verticalLayout_2->addWidget(s_volume);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);


        horizontalLayout_3->addLayout(verticalLayout_2);

        b_close = new QPushButton(centralwidget);
        b_close->setObjectName(QString::fromUtf8("b_close"));

        horizontalLayout_3->addWidget(b_close);

        MusicPlayer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MusicPlayer);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 548, 26));
        MusicPlayer->setMenuBar(menubar);
        statusbar = new QStatusBar(MusicPlayer);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MusicPlayer->setStatusBar(statusbar);

        retranslateUi(MusicPlayer);

        QMetaObject::connectSlotsByName(MusicPlayer);
    } // setupUi

    void retranslateUi(QMainWindow *MusicPlayer)
    {
        MusicPlayer->setWindowTitle(QCoreApplication::translate("MusicPlayer", "MusicPlayer", nullptr));
        b_find->setText(QCoreApplication::translate("MusicPlayer", "Find", nullptr));
        b_backward->setText(QCoreApplication::translate("MusicPlayer", "<|", nullptr));
        b_playPause->setText(QCoreApplication::translate("MusicPlayer", ">", nullptr));
        b_forward->setText(QCoreApplication::translate("MusicPlayer", "|>", nullptr));
        label->setText(QCoreApplication::translate("MusicPlayer", "0", nullptr));
        b_close->setText(QCoreApplication::translate("MusicPlayer", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MusicPlayer: public Ui_MusicPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICPLAYER_H
