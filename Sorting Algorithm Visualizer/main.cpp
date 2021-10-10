#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <time.h>
#include "Rectangle.h"
#include <iostream>

using namespace std;

void getRandHei(vector<Rectangle>& data, const int& amount, const int& width) {
    srand((unsigned)time(0));

    for (int i = 0; i < amount; i++) {
        int randNum = 1 + rand() % 200;
        sf::RectangleShape r(sf::Vector2f(width, randNum));
        Rectangle input = Rectangle(randNum, r);
        input.setShapePos(i, width);
        data.push_back(input);
    }
}

void changeBarColor(sf::RectangleShape& r, const sf::Color& color) {
    r.setFillColor(color);
}

void updateWin(sf::RenderWindow& window, vector<Rectangle>& data) {
    window.clear(sf::Color::Black);
    for (int i = 0 ; i < data.size() ; i++) {
        data[i].updateShapePos(i, 1000 / data.size());
        window.draw(data[i].getShape());
    }
    window.display();
}

void bubbleSort(sf::RenderWindow& window, vector<Rectangle>& data) {
    Rectangle temp = Rectangle();
    for (int i = data.size() - 1 ; i >= 0; i--) {
        for (int k = 0; k < i; k++) {
            changeBarColor(data[k].getShape(), sf::Color::Red);
            changeBarColor(data[k + 1].getShape(), sf::Color::Red);
            if (data[k].getHeight() > data[k + 1].getHeight()) {
                swap(data[k], data[k + 1]);
                updateWin(window, data);
            }       
            changeBarColor(data[k].getShape(), sf::Color::White);
            changeBarColor(data[k+1].getShape(), sf::Color::White);
        }
    }
}

void selectionSort(sf::RenderWindow& window, vector<Rectangle>& data) {
    Rectangle temp = Rectangle();
  
   for(int i = 0 ; i < data.size() ; i++){
       changeBarColor(data[i].getShape(), sf::Color::Red);
       for (int k = i + 1; k < data.size(); k++) {
           changeBarColor(data[k].getShape(), sf::Color::Red);
           if (data[k].getHeight() < data[i].getHeight()){
               swap(data[k], data[i]);
               updateWin(window, data);
           }
           changeBarColor(data[k].getShape(), sf::Color::White);
       }
       changeBarColor(data[i].getShape(), sf::Color::White);
      }
}

int partition(sf::RenderWindow& window, vector<Rectangle>& data, int front, int end) {
    int p = data[end].getHeight();
    int i = front - 1;

    changeBarColor(data[end].getShape(), sf::Color::White);

    for (int j = front; j < end; j++) {
        changeBarColor(data[j].getShape(), sf::Color::White);
        if (p > data[j].getHeight()) {
            i++;
            changeBarColor(data[i].getShape(), sf::Color::Red);
            swap(data[i], data[j]);
            
            updateWin(window, data);
        }
        changeBarColor(data[j].getShape(), sf::Color::Red);
    }
    i++;
    changeBarColor(data[i].getShape(), sf::Color::White);
    swap(data[i], data[end]);
    return i;
}

void quickSort(sf::RenderWindow& window, vector<Rectangle>& data, int front, int end) {
    if (front < end) {
        int p = partition(window, data, front, end);
        quickSort(window, data, front, p - 1);
        quickSort(window, data, p + 1, end);
    }
}

void checkData(vector<Rectangle>& data) {
    for (int i = 0; i < data.size(); i++)
        changeBarColor(data[i].getShape(), sf::Color::Green);
}

int main()
{
    int amount;// num of rectangle
    cout << "How many data you would like to generate?\nYour input: ";
    cin >> amount;
    const double width = 1000.0 / amount;
    vector<Rectangle> data;
 
    getRandHei(data, amount, width);

    sf::RenderWindow window(sf::VideoMode(1000, 500), "Sorting Visualization");

    cout << "\nWhat sorting algorithm you would like to apply:\nA.Bubble sort\nB.Selection Sort\nC.Quick Sort\n";

    // main loop
    while (window.isOpen()) {
       sf::Event event;
            
        while (window.pollEvent(event)) {

            switch (event.type) {
            
            case (sf::Keyboard::Key::Escape || sf::Event::EventType::Closed):
                window.close();
                break;
            case (sf::Event::EventType::KeyPressed): {
                if (event.key.code == sf::Keyboard::Key::A) {
                    bubbleSort(window, data);
                    checkData(data);
                }
                else if (event.key.code == sf::Keyboard::Key::B) {
                    selectionSort(window, data);
                    checkData(data);
                }
                else if (event.key.code == sf::Keyboard::Key::C) {
                    quickSort(window, data, 0, data.size() - 1);
                    checkData(data);
                }
            
                break;
            }
         }
            
            
            updateWin(window, data);
        }
    }
    return 0;
}