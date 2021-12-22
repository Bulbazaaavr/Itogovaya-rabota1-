#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

int x = 0;                  //координата x
int y = 300;                //координата y (появление героя)
int zvyk = 25;              //громкость(от 0 до 100)
float currentFrame = 0;     //номер кадра
float scor = 0.2;           //скорость передвижения героя
float scoranim = 0.005;     //скорость анимации героя

int main()
{
    //Окно программы размером 1000x500 пикселей  
	RenderWindow window(VideoMode(1000, 500), "Sonic 2D!");
	
    //Загрузка 2 картинок
	Texture pers, fon;
	pers.loadFromFile("spriteSonic2.png");
    fon.loadFromFile("fon3.jpg");
    
    //Создание двух спрайтов
    Sprite sPers(pers), sFon(fon);
    sPers.setTexture(pers);                       //загрузка текстуры в спрайт
    sPers.setTextureRect(IntRect(0, 0, 41, 50));  //координаты (x, y, ширина, высота) 
    sPers.setPosition(x, y);                      //местоположение
  
    //Подключение звука
    Music music;        
    music.openFromFile("GreenHill.ogg");
    music.play();
    music.setLoop(true);    //Повтор 
    music.setVolume(zvyk);  //Громкость
    

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))   //основной цикл программы 
        {
            if (event.type == Event::Closed)    //обработка закрытия окна
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            sPers.move(-(scor), 0);  //передвижение спрайта при нажатии левой кнопки

            currentFrame += scoranim; //скорость анимации
            if (currentFrame > 6)  // 6 - всего кадров
            {
                currentFrame -= 6;
            }
            sPers.setTextureRect(IntRect(41 * int(currentFrame)+41, 0, -41, 50)); //изменение первой координаты
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) 
        {
            sPers.move(scor, 0);  //передвижение спрайта при нажатии правой кнопки

            currentFrame += scoranim; //скорость анимации
            if (currentFrame > 6)
            {
                currentFrame -= 6;
            }
            sPers.setTextureRect(IntRect(41 * int(currentFrame), 0, 41, 50)); //изменение первой координаты
        }
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            sPers.move(0, -(scor)); //передвижение спрайта при нажати кнопки вверх
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            sPers.move(0, scor); //передвижение спрайта при нажатии кнопки вниз
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close(); //закрытие окна программы при нажатии Esc
        }

        window.clear();         //очитска экрана
        window.draw(sFon);      //рисовка спрайта №1
        window.draw(sPers);     //рисовка спрайта №2
        window.display();       //вывод
    }

    return 0;
}