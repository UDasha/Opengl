#include"glut.h"

float angle = 0.0f;//���� ��������
float Move = 0.0f;//���������� �����������
float sign = 1;//�����������

void renderScene();//��������� �����
void changeSize(int w, int h);//��������� ������
//void keyPressed(unsigned char key, int x, int y);

int main(int argc, char** argv)//1-� �������� - ���-�� ���������� ����������, 2-� - ��������� �� ��������� ����.(������ �����)
{
	glutInit(&argc, argv);//����=1,����=�������� ���������
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);//��������� ������: 1-� ������������ - �������, 2-� - ������� ��������(������� �����)(������������ ����� ������, � �� ������ �������),3-� - �������� �����(�-������������)
	glutInitWindowPosition(100, 100);//��������� ����� � �������� �� ����
	glutInitWindowSize(400, 400);//������ ������
	glutCreateWindow("Triangle");//������

	glutDisplayFunc(renderScene);//������������ ������� - �������� ���-��� ������ ��������� � ���������� ���������
	glutReshapeFunc(changeSize);//-----''------
	glutIdleFunc(renderScene);//��� �������������� ������
	//glutKeyboardFunc(keyPressed);//��� ������� ����������

	glutMainLoop();//����������� ���� ����� ������ (���� �� ���������� ���������)
	return 1;
}

void renderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//��������� ����� ����� � ����� �������(������� ��� � + ���� ��� ��������� ����� ��������)
	glLoadIdentity();//�������� ��������� �������
	gluLookAt(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);//�����.� ������., ����������� , ������ �������(��� �����.x,y,z)
	
																	 
																	 
	//��������� �������
	glTranslatef(Move, 0.0, Move);//�������� �� ��� �
	Move += 0.001f*sign;//��� ��������
	if (Move > 0.2f || Move < -2.0f)//����� ��������
	{
		sign *= -1;
	}

	/*glRotatef(angle, 0.0f, 1.0f, 0.0f);//�������� ������������(����, ���)�� ��� y
	angle += 0.1f;*/

	glTranslatef(Move, 0.0, 0.0);


	glColor3f(1.0, 0.0, 0.0);//���� ������
	glBegin(GL_TRIANGLES);//������� ������ ������� ������ ������� ���������(�������� �������� �����������)
	glVertex3f(-2.0f, -2.0f, 0.0f);//���������� ������������ �.1
	glVertex3f(0.0f, 2.0f, 0.0f);//���������� ������������ �.2
	glVertex3f(2.0f, -2.0f, 0.0f);//���������� ������������ �.3

	glEnd();
	glutSwapBuffers();//����� �������
}

void changeSize(int w, int h)
{
	if (h == 0) h = 1;//��������, ���� ���� ��������� ������

	float ratio = w*1.0 / h;//����������� ������

	glMatrixMode(GL_PROJECTION);//����� ��������� �����������
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);//�����������: 1-� ���� ������,2-� ����������� ������, 3-� - ���� ������ ����� ������, �� �� ��������� ������������, 4-� - ��������(���� ������)
	glMatrixMode(GL_MODELVIEW);//����� ��������� �������
}

/*void keyPressed(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a'://��� ������� "�" �� ���������� - ����������� ��������� �����
		Move -= 0.05f;
		break;
	case 'd'://��� ������� "d" ����������� ��������� ������
		Move += 0.05f;
		break;
	default:
		break;
	}
}*/
