#include "banddialog.h"
#include "ui_banddialog.h"
#include <QDebug>

bandDialog::bandDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bandDialog)
{
    ui->setupUi(this);

//    QList<QCheckBox *> l_checkboxes = ui->frame->findChildren<QCheckBox *>(QString());
    l_checkboxes = ui->frame->findChildren<QCheckBox *>(QString());
    r_checkboxes = ui->frame_3->findChildren<QCheckBox *>(QString());

    int cbLen = l_checkboxes.length();
    int a, b;
    bool swapped = true;

    qDebug() << Q_FUNC_INFO << "l_checkboxes = " << cbLen;
    while (swapped) {
        swapped = false;
        for(int x = 0; x < (cbLen-1); x++) {
            a = ((l_checkboxes[x]->objectName()).mid(9)).toInt();
            b = ((l_checkboxes[x+1]->objectName()).mid(9)).toInt();
            if(b < a){
                l_checkboxes.swap(x,(x+1));
                swapped = true;
            }
        }
    }

    cbLen = r_checkboxes.length();
    swapped = true;
    while (swapped) {
        swapped = false;
        for(int x = 0; x < (cbLen-1); x++) {
            a = ((r_checkboxes[x]->objectName()).mid(10)).toInt();
            b = ((r_checkboxes[x+1]->objectName()).mid(10)).toInt();
            if(b < a){
                r_checkboxes.swap(x,(x+1));
                swapped = true;
            }
        }
    }

    readSettings();

    QString s = l_checkboxes[9]->objectName();
    qDebug() << s << l_checkboxes[9]->isChecked();
    qDebug() << "checkBox_18 = " << ui->checkBox_18->isChecked();
    qDebug() << l_checkboxes;
    qDebug() << "";
    qDebug() << r_checkboxes;
}

bandDialog::~bandDialog()
{
    writeSettings();
    delete ui;
}


void bandDialog::writeSettings()
{
    QSettings settings("Hermes-Lite", "HL_I2C_Tester_Qt");


    settings.setValue("band0", ui->lineEdit->text());
    settings.setValue("band1", ui->lineEdit_2->text());
    settings.setValue("band2", ui->lineEdit_3->text());
    settings.setValue("band3", ui->lineEdit_4->text());
    settings.setValue("band4", ui->lineEdit_5->text());
    settings.setValue("band5", ui->lineEdit_6->text());
    settings.setValue("band6", ui->lineEdit_7->text());
    settings.setValue("band7", ui->lineEdit_8->text());

    //Transmit checkBoxes
    //Band 0

    qDebug() << "l_checkboxes[0] value = " << l_checkboxes[0]->isChecked();

    settings.setValue("cb1", ui->checkBox_1->isChecked());
    settings.setValue("cb2", ui->checkBox_2->isChecked());
    settings.setValue("cb3", ui->checkBox_3->isChecked());
    settings.setValue("cb4", ui->checkBox_4->isChecked());
    settings.setValue("cb5", ui->checkBox_5->isChecked());
    settings.setValue("cb6", ui->checkBox_6->isChecked());
    settings.setValue("cb7", ui->checkBox_7->isChecked());
    settings.setValue("cb8", ui->checkBox_8->isChecked());
    //Band 1
    settings.setValue("cb9", ui->checkBox_9->isChecked());
    settings.setValue("cb10", ui->checkBox_10->isChecked());
    settings.setValue("cb11", ui->checkBox_11->isChecked());
    settings.setValue("cb12", ui->checkBox_12->isChecked());
    settings.setValue("cb13", ui->checkBox_13->isChecked());
    settings.setValue("cb14", ui->checkBox_14->isChecked());
    settings.setValue("cb15", ui->checkBox_15->isChecked());
    settings.setValue("cb16", ui->checkBox_16->isChecked());
    //Band 2
    settings.setValue("cb17", ui->checkBox_17->isChecked());
    settings.setValue("cb18", ui->checkBox_18->isChecked());
    settings.setValue("cb19", ui->checkBox_19->isChecked());
    settings.setValue("cb20", ui->checkBox_20->isChecked());
    settings.setValue("cb21", ui->checkBox_21->isChecked());
    settings.setValue("cb22", ui->checkBox_22->isChecked());
    settings.setValue("cb23", ui->checkBox_23->isChecked());
    settings.setValue("cb24", ui->checkBox_24->isChecked());
    //Band 3
    settings.setValue("cb25", ui->checkBox_25->isChecked());
    settings.setValue("cb26", ui->checkBox_26->isChecked());
    settings.setValue("cb27", ui->checkBox_27->isChecked());
    settings.setValue("cb28", ui->checkBox_28->isChecked());
    settings.setValue("cb29", ui->checkBox_29->isChecked());
    settings.setValue("cb30", ui->checkBox_30->isChecked());
    settings.setValue("cb31", ui->checkBox_31->isChecked());
    settings.setValue("cb32", ui->checkBox_32->isChecked());
    //Band 4
    settings.setValue("cb33", ui->checkBox_33->isChecked());
    settings.setValue("cb34", ui->checkBox_34->isChecked());
    settings.setValue("cb35", ui->checkBox_35->isChecked());
    settings.setValue("cb36", ui->checkBox_36->isChecked());
    settings.setValue("cb37", ui->checkBox_37->isChecked());
    settings.setValue("cb38", ui->checkBox_38->isChecked());
    settings.setValue("cb39", ui->checkBox_39->isChecked());
    settings.setValue("cb40", ui->checkBox_40->isChecked());
    //Band 5
    settings.setValue("cb41", ui->checkBox_41->isChecked());
    settings.setValue("cb42", ui->checkBox_42->isChecked());
    settings.setValue("cb43", ui->checkBox_43->isChecked());
    settings.setValue("cb44", ui->checkBox_44->isChecked());
    settings.setValue("cb45", ui->checkBox_45->isChecked());
    settings.setValue("cb46", ui->checkBox_46->isChecked());
    settings.setValue("cb47", ui->checkBox_47->isChecked());
    settings.setValue("cb48", ui->checkBox_48->isChecked());
    //Band 6
    settings.setValue("cb49", ui->checkBox_49->isChecked());
    settings.setValue("cb50", ui->checkBox_50->isChecked());
    settings.setValue("cb51", ui->checkBox_51->isChecked());
    settings.setValue("cb52", ui->checkBox_52->isChecked());
    settings.setValue("cb53", ui->checkBox_53->isChecked());
    settings.setValue("cb54", ui->checkBox_54->isChecked());
    settings.setValue("cb55", ui->checkBox_55->isChecked());
    settings.setValue("cb56", ui->checkBox_56->isChecked());
    //Band 7
    settings.setValue("cb57", ui->checkBox_57->isChecked());
    settings.setValue("cb58", ui->checkBox_58->isChecked());
    settings.setValue("cb59", ui->checkBox_59->isChecked());
    settings.setValue("cb60", ui->checkBox_60->isChecked());
    settings.setValue("cb61", ui->checkBox_61->isChecked());
    settings.setValue("cb62", ui->checkBox_62->isChecked());
    settings.setValue("cb63", ui->checkBox_63->isChecked());
    settings.setValue("cb64", ui->checkBox_64->isChecked());

    //Receive checkBoxes
    //Band 0
    settings.setValue("cbr1", ui->checkBoxR_1->isChecked());
    settings.setValue("cbr2", ui->checkBoxR_2->isChecked());
    settings.setValue("cbr3", ui->checkBoxR_3->isChecked());
    settings.setValue("cbr4", ui->checkBoxR_4->isChecked());
    settings.setValue("cbr5", ui->checkBoxR_5->isChecked());
    settings.setValue("cbr6", ui->checkBoxR_6->isChecked());
    settings.setValue("cbr7", ui->checkBoxR_7->isChecked());
    settings.setValue("cbr8", ui->checkBoxR_8->isChecked());
    //Band 1
    settings.setValue("cbr9", ui->checkBoxR_9->isChecked());
    settings.setValue("cbr10", ui->checkBoxR_10->isChecked());
    settings.setValue("cbr11", ui->checkBoxR_11->isChecked());
    settings.setValue("cbr12", ui->checkBoxR_12->isChecked());
    settings.setValue("cbr13", ui->checkBoxR_13->isChecked());
    settings.setValue("cbr14", ui->checkBoxR_14->isChecked());
    settings.setValue("cbr15", ui->checkBoxR_15->isChecked());
    settings.setValue("cbr16", ui->checkBoxR_16->isChecked());
    //Band 2
    settings.setValue("cbr17", ui->checkBoxR_17->isChecked());
    settings.setValue("cbr18", ui->checkBoxR_18->isChecked());
    settings.setValue("cbr19", ui->checkBoxR_19->isChecked());
    settings.setValue("cbr20", ui->checkBoxR_20->isChecked());
    settings.setValue("cbr21", ui->checkBoxR_21->isChecked());
    settings.setValue("cbr22", ui->checkBoxR_22->isChecked());
    settings.setValue("cbr23", ui->checkBoxR_23->isChecked());
    settings.setValue("cbr24", ui->checkBoxR_24->isChecked());
    //Band 3
    settings.setValue("cbr25", ui->checkBoxR_25->isChecked());
    settings.setValue("cbr26", ui->checkBoxR_26->isChecked());
    settings.setValue("cbr27", ui->checkBoxR_27->isChecked());
    settings.setValue("cbr28", ui->checkBoxR_28->isChecked());
    settings.setValue("cbr29", ui->checkBoxR_29->isChecked());
    settings.setValue("cbr30", ui->checkBoxR_30->isChecked());
    settings.setValue("cbr31", ui->checkBoxR_31->isChecked());
    settings.setValue("cbr32", ui->checkBoxR_32->isChecked());
    //Band 4
    settings.setValue("cbr33", ui->checkBoxR_33->isChecked());
    settings.setValue("cbr34", ui->checkBoxR_34->isChecked());
    settings.setValue("cbr35", ui->checkBoxR_35->isChecked());
    settings.setValue("cbr36", ui->checkBoxR_36->isChecked());
    settings.setValue("cbr37", ui->checkBoxR_37->isChecked());
    settings.setValue("cbr38", ui->checkBoxR_38->isChecked());
    settings.setValue("cbr39", ui->checkBoxR_39->isChecked());
    settings.setValue("cbr40", ui->checkBoxR_40->isChecked());
    //Band 5
    settings.setValue("cbr41", ui->checkBoxR_41->isChecked());
    settings.setValue("cbr42", ui->checkBoxR_42->isChecked());
    settings.setValue("cbr43", ui->checkBoxR_43->isChecked());
    settings.setValue("cbr44", ui->checkBoxR_44->isChecked());
    settings.setValue("cbr45", ui->checkBoxR_45->isChecked());
    settings.setValue("cbr46", ui->checkBoxR_46->isChecked());
    settings.setValue("cbr47", ui->checkBoxR_47->isChecked());
    settings.setValue("cbr48", ui->checkBoxR_48->isChecked());
    //Band 6
    settings.setValue("cbr49", ui->checkBoxR_49->isChecked());
    settings.setValue("cbr50", ui->checkBoxR_50->isChecked());
    settings.setValue("cbr51", ui->checkBoxR_51->isChecked());
    settings.setValue("cbr52", ui->checkBoxR_52->isChecked());
    settings.setValue("cbr53", ui->checkBoxR_53->isChecked());
    settings.setValue("cbr54", ui->checkBoxR_54->isChecked());
    settings.setValue("cbr55", ui->checkBoxR_55->isChecked());
    settings.setValue("cbr56", ui->checkBoxR_56->isChecked());
    //Band 7
    settings.setValue("cbr57", ui->checkBoxR_57->isChecked());
    settings.setValue("cbr58", ui->checkBoxR_58->isChecked());
    settings.setValue("cbr59", ui->checkBoxR_59->isChecked());
    settings.setValue("cbr60", ui->checkBoxR_60->isChecked());
    settings.setValue("cbr61", ui->checkBoxR_61->isChecked());
    settings.setValue("cbr62", ui->checkBoxR_62->isChecked());
    settings.setValue("cbr63", ui->checkBoxR_63->isChecked());
    settings.setValue("cbr64", ui->checkBoxR_64->isChecked());
}

void bandDialog::readSettings()
{
    QSettings settings("Hermes-Lite", "HL_I2C_Tester_Qt");

    ui->lineEdit->setText(settings.value("band0", "Band 0").toString());
    ui->lineEdit_2->setText(settings.value("band1", "Band 1").toString());
    ui->lineEdit_3->setText(settings.value("band2", "Band 2").toString());
    ui->lineEdit_4->setText(settings.value("band3", "Band 3").toString());
    ui->lineEdit_5->setText(settings.value("band4", "Band 4").toString());
    ui->lineEdit_6->setText(settings.value("band5", "Band 5").toString());
    ui->lineEdit_7->setText(settings.value("band6", "Band 6").toString());
    ui->lineEdit_8->setText(settings.value("band7", "Band 7").toString());
    ui->lineEditR->setText(settings.value("band0", "Band 0").toString());
    ui->lineEditR_2->setText(settings.value("band1", "Band 1").toString());
    ui->lineEditR_3->setText(settings.value("band2", "Band 2").toString());
    ui->lineEditR_4->setText(settings.value("band3", "Band 3").toString());
    ui->lineEditR_5->setText(settings.value("band4", "Band 4").toString());
    ui->lineEditR_6->setText(settings.value("band5", "Band 5").toString());
    ui->lineEditR_7->setText(settings.value("band6", "Band 6").toString());
    ui->lineEditR_8->setText(settings.value("band7", "Band 7").toString());

    //Transmit checkBoxes
    //Band 0
    ui->checkBox_1->setChecked(settings.value("cb1", false).toBool());
    ui->checkBox_2->setChecked(settings.value("cb2", false).toBool());
    ui->checkBox_3->setChecked(settings.value("cb3", false).toBool());
    ui->checkBox_4->setChecked(settings.value("cb4", false).toBool());
    ui->checkBox_5->setChecked(settings.value("cb5", false).toBool());
    ui->checkBox_6->setChecked(settings.value("cb6", false).toBool());
    ui->checkBox_7->setChecked(settings.value("cb7", false).toBool());
    ui->checkBox_8->setChecked(settings.value("cb8", false).toBool());
    // Band 1
    ui->checkBox_9->setChecked(settings.value("cb9", false).toBool());
    ui->checkBox_10->setChecked(settings.value("cb10", false).toBool());
    ui->checkBox_11->setChecked(settings.value("cb11", false).toBool());
    ui->checkBox_12->setChecked(settings.value("cb12", false).toBool());
    ui->checkBox_13->setChecked(settings.value("cb13", false).toBool());
    ui->checkBox_14->setChecked(settings.value("cb14", false).toBool());
    ui->checkBox_15->setChecked(settings.value("cb15", false).toBool());
    ui->checkBox_16->setChecked(settings.value("cb16", false).toBool());
    //Band 2
    ui->checkBox_17->setChecked(settings.value("cb17", false).toBool());
    ui->checkBox_18->setChecked(settings.value("cb18", false).toBool());
    ui->checkBox_19->setChecked(settings.value("cb19", false).toBool());
    ui->checkBox_20->setChecked(settings.value("cb20", false).toBool());
    ui->checkBox_21->setChecked(settings.value("cb21", false).toBool());
    ui->checkBox_22->setChecked(settings.value("cb22", false).toBool());
    ui->checkBox_23->setChecked(settings.value("cb23", false).toBool());
    ui->checkBox_24->setChecked(settings.value("cb24", false).toBool());
    //Band 3
    ui->checkBox_25->setChecked(settings.value("cb25", false).toBool());
    ui->checkBox_26->setChecked(settings.value("cb26", false).toBool());
    ui->checkBox_27->setChecked(settings.value("cb27", false).toBool());
    ui->checkBox_28->setChecked(settings.value("cb28", false).toBool());
    ui->checkBox_29->setChecked(settings.value("cb29", false).toBool());
    ui->checkBox_30->setChecked(settings.value("cb30", false).toBool());
    ui->checkBox_31->setChecked(settings.value("cb31", false).toBool());
    ui->checkBox_32->setChecked(settings.value("cb32", false).toBool());
    //Band 4
    ui->checkBox_33->setChecked(settings.value("cb33", false).toBool());
    ui->checkBox_34->setChecked(settings.value("cb34", false).toBool());
    ui->checkBox_35->setChecked(settings.value("cb35", false).toBool());
    ui->checkBox_36->setChecked(settings.value("cb36", false).toBool());
    ui->checkBox_37->setChecked(settings.value("cb37", false).toBool());
    ui->checkBox_38->setChecked(settings.value("cb38", false).toBool());
    ui->checkBox_39->setChecked(settings.value("cb39", false).toBool());
    ui->checkBox_40->setChecked(settings.value("cb40", false).toBool());
    //Band 5
    ui->checkBox_41->setChecked(settings.value("cb41", false).toBool());
    ui->checkBox_42->setChecked(settings.value("cb42", false).toBool());
    ui->checkBox_43->setChecked(settings.value("cb43", false).toBool());
    ui->checkBox_44->setChecked(settings.value("cb44", false).toBool());
    ui->checkBox_45->setChecked(settings.value("cb45", false).toBool());
    ui->checkBox_46->setChecked(settings.value("cb46", false).toBool());
    ui->checkBox_47->setChecked(settings.value("cb47", false).toBool());
    ui->checkBox_48->setChecked(settings.value("cb48", false).toBool());
    //Band 6
    ui->checkBox_49->setChecked(settings.value("cb49", false).toBool());
    ui->checkBox_50->setChecked(settings.value("cb50", false).toBool());
    ui->checkBox_51->setChecked(settings.value("cb51", false).toBool());
    ui->checkBox_52->setChecked(settings.value("cb52", false).toBool());
    ui->checkBox_53->setChecked(settings.value("cb53", false).toBool());
    ui->checkBox_54->setChecked(settings.value("cb54", false).toBool());
    ui->checkBox_55->setChecked(settings.value("cb55", false).toBool());
    ui->checkBox_56->setChecked(settings.value("cb56", false).toBool());
    //Band 7
    ui->checkBox_57->setChecked(settings.value("cb57", false).toBool());
    ui->checkBox_58->setChecked(settings.value("cb58", false).toBool());
    ui->checkBox_59->setChecked(settings.value("cb59", false).toBool());
    ui->checkBox_60->setChecked(settings.value("cb60", false).toBool());
    ui->checkBox_61->setChecked(settings.value("cb61", false).toBool());
    ui->checkBox_62->setChecked(settings.value("cb62", false).toBool());
    ui->checkBox_63->setChecked(settings.value("cb63", false).toBool());
    ui->checkBox_64->setChecked(settings.value("cb64", false).toBool());

    //Receive checkBoxes
    //Band 0
    ui->checkBoxR_1->setChecked(settings.value("cbr1", false).toBool());
    ui->checkBoxR_2->setChecked(settings.value("cbr2", false).toBool());
    ui->checkBoxR_3->setChecked(settings.value("cbr3", false).toBool());
    ui->checkBoxR_4->setChecked(settings.value("cbr4", false).toBool());
    ui->checkBoxR_5->setChecked(settings.value("cbr5", false).toBool());
    ui->checkBoxR_6->setChecked(settings.value("cbr6", false).toBool());
    ui->checkBoxR_7->setChecked(settings.value("cbr7", false).toBool());
    ui->checkBoxR_8->setChecked(settings.value("cbr8", false).toBool());
    // Band 1
    ui->checkBoxR_9->setChecked(settings.value("cbr9", false).toBool());
    ui->checkBoxR_10->setChecked(settings.value("cbr10", false).toBool());
    ui->checkBoxR_11->setChecked(settings.value("cbr11", false).toBool());
    ui->checkBoxR_12->setChecked(settings.value("cbr12", false).toBool());
    ui->checkBoxR_13->setChecked(settings.value("cbr13", false).toBool());
    ui->checkBoxR_14->setChecked(settings.value("cbr14", false).toBool());
    ui->checkBoxR_15->setChecked(settings.value("cbr15", false).toBool());
    ui->checkBoxR_16->setChecked(settings.value("cbr16", false).toBool());
    //Band 2
    ui->checkBoxR_17->setChecked(settings.value("cbr17", false).toBool());
    ui->checkBoxR_18->setChecked(settings.value("cbr18", false).toBool());
    ui->checkBoxR_19->setChecked(settings.value("cbr19", false).toBool());
    ui->checkBoxR_20->setChecked(settings.value("cbr20", false).toBool());
    ui->checkBoxR_21->setChecked(settings.value("cbr21", false).toBool());
    ui->checkBoxR_22->setChecked(settings.value("cbr22", false).toBool());
    ui->checkBoxR_23->setChecked(settings.value("cbr23", false).toBool());
    ui->checkBoxR_24->setChecked(settings.value("cbr24", false).toBool());
    //Band 3
    ui->checkBoxR_25->setChecked(settings.value("cbr25", false).toBool());
    ui->checkBoxR_26->setChecked(settings.value("cbr26", false).toBool());
    ui->checkBoxR_27->setChecked(settings.value("cbr27", false).toBool());
    ui->checkBoxR_28->setChecked(settings.value("cbr28", false).toBool());
    ui->checkBoxR_29->setChecked(settings.value("cbr29", false).toBool());
    ui->checkBoxR_30->setChecked(settings.value("cbr30", false).toBool());
    ui->checkBoxR_31->setChecked(settings.value("cbr31", false).toBool());
    ui->checkBoxR_32->setChecked(settings.value("cbr32", false).toBool());
    //Band 4
    ui->checkBoxR_33->setChecked(settings.value("cbr33", false).toBool());
    ui->checkBoxR_34->setChecked(settings.value("cbr34", false).toBool());
    ui->checkBoxR_35->setChecked(settings.value("cbr35", false).toBool());
    ui->checkBoxR_36->setChecked(settings.value("cbr36", false).toBool());
    ui->checkBoxR_37->setChecked(settings.value("cbr37", false).toBool());
    ui->checkBoxR_38->setChecked(settings.value("cbr38", false).toBool());
    ui->checkBoxR_39->setChecked(settings.value("cbr39", false).toBool());
    ui->checkBoxR_40->setChecked(settings.value("cbr40", false).toBool());
    //Band 5
    ui->checkBoxR_41->setChecked(settings.value("cbr41", false).toBool());
    ui->checkBoxR_42->setChecked(settings.value("cbr42", false).toBool());
    ui->checkBoxR_43->setChecked(settings.value("cbr43", false).toBool());
    ui->checkBoxR_44->setChecked(settings.value("cbr44", false).toBool());
    ui->checkBoxR_45->setChecked(settings.value("cbr45", false).toBool());
    ui->checkBoxR_46->setChecked(settings.value("cbr46", false).toBool());
    ui->checkBoxR_47->setChecked(settings.value("cbr47", false).toBool());
    ui->checkBoxR_48->setChecked(settings.value("cbr48", false).toBool());
    //Band 6
    ui->checkBoxR_49->setChecked(settings.value("cbr49", false).toBool());
    ui->checkBoxR_50->setChecked(settings.value("cbr50", false).toBool());
    ui->checkBoxR_51->setChecked(settings.value("cbr51", false).toBool());
    ui->checkBoxR_52->setChecked(settings.value("cbr52", false).toBool());
    ui->checkBoxR_53->setChecked(settings.value("cbr53", false).toBool());
    ui->checkBoxR_54->setChecked(settings.value("cbr54", false).toBool());
    ui->checkBoxR_55->setChecked(settings.value("cbr55", false).toBool());
    ui->checkBoxR_56->setChecked(settings.value("cbr56", false).toBool());
    //Band 7
    ui->checkBoxR_57->setChecked(settings.value("cbr57", false).toBool());
    ui->checkBoxR_58->setChecked(settings.value("cbr58", false).toBool());
    ui->checkBoxR_59->setChecked(settings.value("cbr59", false).toBool());
    ui->checkBoxR_60->setChecked(settings.value("cbr60", false).toBool());
    ui->checkBoxR_61->setChecked(settings.value("cbr61", false).toBool());
    ui->checkBoxR_62->setChecked(settings.value("cbr62", false).toBool());
    ui->checkBoxR_63->setChecked(settings.value("cbr63", false).toBool());
    ui->checkBoxR_64->setChecked(settings.value("cbr64", false).toBool());
}

