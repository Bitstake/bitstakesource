#include "bitstakepage.h"
#include "ui_bitstakepage.h"

#include "clientmodel.h"
#include "walletmodel.h"
#include "bitcoinunits.h"
#include "optionsmodel.h"
#include "transactiontablemodel.h"
#include "transactionfilterproxy.h"
#include "guiutil.h"
#include "guiconstants.h"

#include <QAbstractItemDelegate>
#include <QPainter>

#define DECORATION_SIZE 64


#include "bitstakepage.moc"

BitStakePage::BitStakePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BitStakePage),
    walletModel(0),
    clientModel(0)
{
    ui->setupUi(this);
    nam = new QNetworkAccessManager(this);           
    ui->webViewBitStake->setHidden(true);
    connect(nam,SIGNAL(finished(QNetworkReply*)),this,SLOT(finished(QNetworkReply*)));          
    connect(ui->submitButton,SIGNAL(clicked()),this,SLOT(GetHttpContent()));
}

BitStakePage::~BitStakePage()
{
    delete ui;
}

void BitStakePage::setClientModel(ClientModel *model)
{
    this->clientModel = model;
    if(model)
    {
    }
}

void BitStakePage::setWalletModel(WalletModel *model)
{
    this->walletModel = model;
}

void BitStakePage::finished(QNetworkReply *reply) {
  ui->webViewBitStake->setHidden(false);
  
}

void BitStakePage::GetHttpContent() {
  ui->webViewBitStake->setHidden(false);
  ui->submitButton->setHidden(true);

  QString url = "https://bitstake.info/";

  ui->webViewBitStake->load(QNetworkRequest(url));

}
