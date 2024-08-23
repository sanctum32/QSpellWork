#include "mainwindow.hpp"
#include "./ui_mainwindow.h"
#include "JsonData/JsonData.hpp"

// Base implementation
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // resultList
    ui->resultList->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->resultList->horizontalHeader()->resizeSection(0, 55);

    // statusBar
    ui->statusBar->setStyleSheet("padding: 5px;");

    // SpellFamilyFilter
    ui->SpellFamilyFilter->setEditable(true);
    ui->SpellFamilyFilter->setMaxVisibleItems(10);
    for (const auto& spellFamily : QSpellWorkJson::SpellFamilyInfo)
    {
        ui->SpellFamilyFilter->addItem(spellFamily.second);
    }

    // SpellAuraTypeFilter
    ui->SpellAuraTypeFilter->setEditable(true);
    ui->SpellAuraTypeFilter->setMaxVisibleItems(10);
    for (const auto& spellAuraTypes : QSpellWorkJson::SpellAuraTypes)
    {
        ui->SpellAuraTypeFilter->addItem(spellAuraTypes.second);
    }

    // SpellEffectFilter
    ui->SpellEffectFilter->setEditable(true);
    ui->SpellEffectFilter->setMaxVisibleItems(10);
    for (const auto& spellEffect : QSpellWorkJson::SpellEffectNames)
    {
        ui->SpellEffectFilter->addItem(spellEffect.second);
    }

    // SpellTargetFilterA
    ui->SpellTargetFilterA->setEditable(true);
    ui->SpellTargetFilterA->setMaxVisibleItems(10);
    for (const auto& targetName : QSpellWorkJson::SpellTargetNames)
    {
        ui->SpellTargetFilterA->addItem(targetName.second);
    }

    // SpellTargetFilterB
    ui->SpellTargetFilterB->setEditable(true);
    ui->SpellTargetFilterB->setMaxVisibleItems(10);
    for (const auto& targetName : QSpellWorkJson::SpellTargetNames)
    {
        ui->SpellTargetFilterB->addItem(targetName.second);
    }

    // Signal connections
    QObject::connect(ui->searchBtn,        &QPushButton::clicked,     this, &MainWindow::onSearchBtnClicked);
    QObject::connect(ui->spellIdNameInput, &QLineEdit::returnPressed, this, &MainWindow::onSpellIdNameInputReturnPressed);
    QObject::connect(ui->resultList,       &QTableWidget::itemClicked,    this, &MainWindow::onResultListClick);
    QObject::connect(ui->levelScalingSlider, &QSlider::valueChanged, this, &MainWindow::onLevelScalingSliderValueChange);
}

MainWindow::~MainWindow() = default;
