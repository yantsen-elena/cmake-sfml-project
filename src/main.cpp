
        // // Ограничение скорости перемещения
        // if (static_cast<int>(circlePosition.x) % cellSize != 0 || static_cast<int>(circlePosition.y) % cellSize!= 0)
        //     circlePosition.x = std::round(circlePosition.x / cellSize) * cellSize;
        // if (static_cast<int>(circlePosition.y) % cellSize != 0)
        //     circlePosition.y = std::round(circlePosition.y / cellSize) * cellSize;


#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow{ { 500u, 500u }, "CMake SFML Project" };
    window.setFramerateLimit(144);
    const int cellSize = 50;

    // Создание кружка
    sf::CircleShape circle(cellSize / 2);
    circle.setFillColor(sf::Color::Yellow);

    sf::Vector2f circlePosition(50, 50); // Центр окна



    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Обновление позиции кружка
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && circlePosition.x > 0) {
            circlePosition.x -= cellSize;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && circlePosition.x < 450) // Учитывая размер окна 500x500
            circlePosition.x += cellSize;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && circlePosition.y > 0)
            circlePosition.y -= cellSize;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && circlePosition.y < 450) // Учитывая размер окна 500x500
            circlePosition.y += cellSize;
        
        circle.setPosition(circlePosition);// Установка позиции кружка
        window.clear();//очищает окно, удаляя все предыдущие графические элементы.

        // Рисование кружка
        window.draw(circle);
        for (int i = 0; i <= 10; ++i)
        {
            sf::Vertex line[2];
            line[0].position = sf::Vector2f(i * cellSize, 0);
            line[1].position = sf::Vector2f(i * cellSize, 500);
            window.draw(line, 2, sf::Lines);
            line[0].position = sf::Vector2f(0, i * cellSize);
            line[1].position = sf::Vector2f(500, i * cellSize);
            window.draw(line, 2, sf::Lines);
        }

        window.display();
        //остановка для ограничения скорости движения кружка
        sf::sleep(sf::seconds(0.07f));
    }

    return 0;
}
