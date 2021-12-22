#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

int x = 0;                  //���������� x
int y = 300;                //���������� y (��������� �����)
int zvyk = 25;              //���������(�� 0 �� 100)
float currentFrame = 0;     //����� �����
float scor = 0.2;           //�������� ������������ �����
float scoranim = 0.005;     //�������� �������� �����

int main()
{
    //���� ��������� �������� 1000x500 ��������  
	RenderWindow window(VideoMode(1000, 500), "Sonic 2D!");
	
    //�������� 2 ��������
	Texture pers, fon;
	pers.loadFromFile("spriteSonic2.png");
    fon.loadFromFile("fon3.jpg");
    
    //�������� ���� ��������
    Sprite sPers(pers), sFon(fon);
    sPers.setTexture(pers);                       //�������� �������� � ������
    sPers.setTextureRect(IntRect(0, 0, 41, 50));  //���������� (x, y, ������, ������) 
    sPers.setPosition(x, y);                      //��������������
  
    //����������� �����
    Music music;        
    music.openFromFile("GreenHill.ogg");
    music.play();
    music.setLoop(true);    //������ 
    music.setVolume(zvyk);  //���������
    

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))   //�������� ���� ��������� 
        {
            if (event.type == Event::Closed)    //��������� �������� ����
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            sPers.move(-(scor), 0);  //������������ ������� ��� ������� ����� ������

            currentFrame += scoranim; //�������� ��������
            if (currentFrame > 6)  // 6 - ����� ������
            {
                currentFrame -= 6;
            }
            sPers.setTextureRect(IntRect(41 * int(currentFrame)+41, 0, -41, 50)); //��������� ������ ����������
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) 
        {
            sPers.move(scor, 0);  //������������ ������� ��� ������� ������ ������

            currentFrame += scoranim; //�������� ��������
            if (currentFrame > 6)
            {
                currentFrame -= 6;
            }
            sPers.setTextureRect(IntRect(41 * int(currentFrame), 0, 41, 50)); //��������� ������ ����������
        }
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            sPers.move(0, -(scor)); //������������ ������� ��� ������ ������ �����
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            sPers.move(0, scor); //������������ ������� ��� ������� ������ ����
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close(); //�������� ���� ��������� ��� ������� Esc
        }

        window.clear();         //������� ������
        window.draw(sFon);      //������� ������� �1
        window.draw(sPers);     //������� ������� �2
        window.display();       //�����
    }

    return 0;
}