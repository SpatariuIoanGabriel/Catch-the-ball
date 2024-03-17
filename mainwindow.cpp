#include "mainwindow.h"
#include <QRandomGenerator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), score(0), timeLeft(30), ballRadius(20) {
    setFixedSize(800, 600);

    ballPos = QPoint(400, 300);

    gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, this, &MainWindow::updateGame);
    gameTimer->start(1000);
}

MainWindow::~MainWindow() {}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    painter.setBrush(Qt::red);
    painter.drawEllipse(ballPos, ballRadius, ballRadius);

    painter.drawText(rect(), Qt::AlignTop | Qt::AlignLeft, "Score: " + QString::number(score) + " Time left: " + QString::number(timeLeft));
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    QPoint clickPos = event->pos();
    if (QLineF(clickPos, ballPos).length() < ballRadius) {
        score++;
        int newX = QRandomGenerator::global()->bounded(ballRadius, width() - ballRadius);
        int newY = QRandomGenerator::global()->bounded(ballRadius, height() - ballRadius);
        ballPos = QPoint(newX, newY);
    }
    QWidget::update();
}

void MainWindow::updateGame() {
    timeLeft--;
    if (timeLeft <= 0) {
        gameTimer->stop();
        QMessageBox::information(this, "Game Over", "Your score: " + QString::number(score));
        close();
    }
    QWidget::update();
}
