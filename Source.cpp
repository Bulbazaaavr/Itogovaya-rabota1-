#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

int x = 0;                  //координата x
int y = 300;                //координата y (по€вление геро€)
int zvyk = 15;              //громкость(от 0 до 100)
float currentFrame = 0;     //номер кадра
float scor = 0.2;           //скорость передвижени€ геро€
float scoranim = 0.005;     //скорость анимации геро€

int main()
{
    //ќкно программы размером 1000x500 пикселей  
	RenderWindow window(VideoMode(1000, 500), "Sonic 2D!");
	
    //«агрузка 2 картинок
	Texture pers, fon;
	pers.loadFromFile("image/spriteSonic2.png");
    fon.loadFromFile("image/fon3.jpg");
    
    //—оздание двух спрайтов
    Sprite sPers(pers), sFon(fon);
    sPers.setTexture(pers);                       //загрузка текстуры в спрайт
    sPers.setTextureRect(IntRect(0, 0, 41, 50));  //координаты (x, y, ширина, высота) 
    sPers.setPosition(x, y);                      //местоположение
  
    //ѕодключение звука
    Music music;        
    music.openFromFile("music/GreenHill.ogg");
    music.play();
    music.setLoop(true);    //ѕовтор 
    music.setVolume(zvyk);  //√ромкость

    //ƒобавление иконки
    Image icon;
    if (!icon.loadFromFile("image/icon.png"))
    {
        return 2;
    }
    window.setIcon(32, 32, icon.getPixelsPtr());
    

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))   //основной цикл программы 
        {
            if (event.type == Event::Closed)    //обработка закрыти€ окна
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
        window.draw(sFon);      //рисовка спрайта є1
        window.draw(sPers);     //рисовка спрайта є2
        window.display();       //вывод
    }

    return 0;
}