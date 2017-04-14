#include"glut.h"

float angle = 0.0f;//угол поворота
float Move = 0.0f;//расстояние перемещения
float sign = 1;//направление

void renderScene();//отрисовка сцены
void changeSize(int w, int h);//изменение экрана
//void keyPressed(unsigned char key, int x, int y);

int main(int argc, char** argv)//1-й аргумент - кол-во переданных аргументов, 2-й - указатель на указатель масс.(массив строк)
{
	glutInit(&argc, argv);//аргс=1,аргв=название программы
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);//настройка экрана: 1-я составляющая - глубина, 2-я - убирает мерцание(двойной буфер)(зарисовывает новым кадром, а не черным экраном),3-й - цветовая схема(А-прозрачность)
	glutInitWindowPosition(100, 100);//начальная точка в пикселях от угла
	glutInitWindowSize(400, 400);//размер экрана
	glutCreateWindow("Triangle");//фигура

	glutDisplayFunc(renderScene);//указательная функция - прототип фун-ции должен совпадать с прототипом указателя
	glutReshapeFunc(changeSize);//-----''------
	glutIdleFunc(renderScene);//для восстановления экрана
	//glutKeyboardFunc(keyPressed);//для нажатия клавиатуры

	glutMainLoop();//бесконечный цикл смены кадров (пока не закончится программа)
	return 1;
}

void renderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//ОЧИЩАЕТСЯ БУФЕР ЦВЕТА и буфер глубины(стираем все и + цвет для отрисовки новых объектов)
	glLoadIdentity();//загрузка единичной матрицы
	gluLookAt(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);//коорд.в простр., направление , вектор нормали(все коорд.x,y,z)
	
																	 
																	 
	//изменение объекта
	glTranslatef(Move, 0.0, Move);//движение по оси х
	Move += 0.001f*sign;//шаг движения
	if (Move > 0.2f || Move < -2.0f)//рамки движения
	{
		sign *= -1;
	}

	/*glRotatef(angle, 0.0f, 1.0f, 0.0f);//вращение треугольника(угол, оси)по оси y
	angle += 0.1f;*/

	glTranslatef(Move, 0.0, 0.0);


	glColor3f(1.0, 0.0, 0.0);//цвет обїекта
	glBegin(GL_TRIANGLES);//границы внутри которых заданы вершины примитива(начинаем рисовать треугольник)
	glVertex3f(-2.0f, -2.0f, 0.0f);//координаты триугольника т.1
	glVertex3f(0.0f, 2.0f, 0.0f);//координаты триугольника т.2
	glVertex3f(2.0f, -2.0f, 0.0f);//координаты триугольника т.3

	glEnd();
	glutSwapBuffers();//смена буферов
}

void changeSize(int w, int h)
{
	if (h == 0) h = 1;//проверка, чтоб была ненулевая высота

	float ratio = w*1.0 / h;//соотношение сторон

	glMatrixMode(GL_PROJECTION);//режим устоновки перспективы
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);//перспектива: 1-е угол камеры,2-е соотношение сторон, 3-е - если объект очень близок, то он перестает отображаться, 4-е - наоборот(если далеко)
	glMatrixMode(GL_MODELVIEW);//режим отрисовки объекта
}

/*void keyPressed(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a'://при нажатии "а" на клавиатуре - треугольник двигается влево
		Move -= 0.05f;
		break;
	case 'd'://при нажатии "d" треугольник двигается вправо
		Move += 0.05f;
		break;
	default:
		break;
	}
}*/
