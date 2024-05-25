#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QTime>
#include <QPixmap>
#include <cstdlib>

// Define the maximum number of dice
const int MAX_DICE = 3;

// Define the Dice class
class Dice {
public:
    // Roll the dice and return the result
    static int roll() {
        return rand() % 6 + 1;
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Seed the random number generator
    srand(static_cast<unsigned int>(QTime::currentTime().msec()));

    // Create the main window
    QMainWindow mainWindow;

    // Set up the background image
    QPixmap backgroundImage("/Users/mrlaw/MyDoc/CPP/DiceRoller/images/dice.png");
    QPalette palette;
    palette.setBrush(QPalette::Background, backgroundImage);
    mainWindow.setPalette(palette);

    // Create a vertical layout for the central widget
    QVBoxLayout layout;
    QWidget centralWidget;
    centralWidget.setLayout(&layout);
    mainWindow.setCentralWidget(&centralWidget);

    // Create a label to display the dice rolls
    QLabel diceLabel;
    layout.addWidget(&diceLabel);

    // Create a button to roll the dice
    QPushButton playButton("Play");
    playButton.setFont(QFont("Arial", 30)); // Set font size to 16
    playButton.setStyleSheet("background-color: #4CAF50; color: white;"); // Set background color to green and text color to white
    // playButton.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding); // Auto-expand button size
    layout.addWidget(&playButton);

    // Create a button to exit the application
    QPushButton exitButton("Exit");
    exitButton.setFont(QFont("Arial", 30)); // Set font size to 16
    exitButton.setStyleSheet("background-color: #09060f; color: white;"); // Set background color to green and text color to white
    // exitButton.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding); // Auto-expand button size
    layout.addWidget(&exitButton);

    // Connect the button's clicked signal to a lambda function
    QObject::connect(&playButton, &QPushButton::clicked, [&]() {
        QString message = "Dice rolls:\n";

        // Roll the dice and update the message
        for (int i = 0; i < MAX_DICE; ++i) {
            int rollResult = Dice::roll();
            message += QString("Dice %1: %2\n").arg(i + 1).arg(rollResult);
        }

        // Show the message box with the dice rolls
        QMessageBox::information(&mainWindow, "Dice Rolls", message);
    });

    // Connect the exit button's clicked signal to the application's quit() slot
    QObject::connect(&exitButton, &QPushButton::clicked, &app, &QApplication::quit);

    // Set up the main window
    mainWindow.setWindowTitle("Dice Game");
    mainWindow.resize(300, 200);
    mainWindow.show();

    // Execute the application
    return app.exec();
}
