/**********
 * TUGAS BESAR TAHAP #1
 KELOMPOK 2
 1. Marselino Adimas Visi Pratama (200710640)
 2. Jonathan Michael Widodo (200710630)
 3. Seto Herlambang (200710836)
 4. Valentinus Edward Hutomo (200710571)
 *
 **********/

#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include "glut.h"

/**********
 * Function Declarations
 *
 **********/

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
WPARAM wParam, LPARAM lParam);
void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC);
void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC);

//******************
// Awal kode yang diambil dari bukunya Suyoto
void Inisialisasi(int lebar, int tinggi)
{
	
	glShadeModel (GL_FLAT);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClearAccum(0.0, 0.0, 0.0, 0.0);
  	glViewport (0, 0, lebar, tinggi); 
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ( );
	gluPerspective(60.0, (GLfloat) lebar/(GLfloat) tinggi, 1.0, 20.0);
	glMatrixMode (GL_MODELVIEW);

	// hidupkan pencahayaan
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
}
// Akhir kode yang diambil dari bukunya Suyoto
//******************

/**********
 * WinMain
 *
 **********/
 
 void DrawTable()
{
    // Bawah meja
    glPushMatrix();
    glTranslatef(0.0f, -1.2f, -5.0);
    glScalef(2.5f, 0.1f, 2.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Kaki meja
    float legHeight = -1.6f;
    float legOffset = 5.0f;
    float legSize = 0.1f;

    glPushMatrix();
    glTranslatef(-1.1f, legHeight, -4.2f);
    glScalef(legSize, 1.0f, legSize);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.1f, legHeight, -4.2f);
    glScalef(legSize, 1.0f, legSize);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.1f, legHeight, -5.6f);
    glScalef(legSize, 1.0f, legSize);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.1f, legHeight, -5.6f);
    glScalef(legSize, 1.0f, legSize);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void DrawChair()
{
    // Bawah kursi
    glPushMatrix();
    glTranslatef(2.0f, -1.3f, -4.0f);
    glScalef(0.8f, 0.1f, 0.8f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Punggung kursi
    glPushMatrix();
    glTranslatef(2.0f, -0.9f, -4.4f);
    glScalef(0.8f, 0.8f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Kaki kursi
    float legHeight = -1.8f;
    float legOffset = 0.4f;
    float legSize = 0.1f;

    glPushMatrix();
    glTranslatef(2.3f, legHeight, -3.6f);
    glScalef(legSize, 1.0f, legSize);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.7f, legHeight, -3.6f);
    glScalef(legSize, 1.0f, legSize);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.3f, legHeight, -4.4f);
    glScalef(legSize, 1.0f, legSize);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.7f, legHeight, -4.4f);
    glScalef(legSize, 1.0f, legSize);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void DrawFloor()
{
    glPushMatrix();
    glTranslatef(0.0f, -2.0f, -5.0f);
    glScalef(5.5f, 0.1f, 5.5f);
    glutSolidCube(1.0f);
    glPopMatrix();
}

// Fungsi untuk menggambar dinding
void DrawWalls()
{
    // Gambar dinding kiri
    glPushMatrix();
    glTranslatef(-1.0f, 0.0f, 0.0f);
    glRotatef (20, 0, 0, 0);
    glScalef(0.1f, 5.0f, 5.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Gambar dinding kanan
    glPushMatrix();
    glTranslatef(1.0f, 0.0f, 0.0f);
    glRotatef (20, 0, 0, 0);
    glScalef(0.1f, 5.0f, 5.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Gambar dinding belakang
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -6.5f);
    glScalef(5.5f, 5.0f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();
}

int WINAPI 
WinMain (HINSTANCE hInstance,
         HINSTANCE hPrevInstance,
         LPSTR lpCmdLine,
         int iCmdShow)
{
    WNDCLASS wc;
    HWND hWnd;
    HDC hDC;
    HGLRC hRC;        
    MSG msg;
    BOOL bQuit = FALSE;
    
	GLfloat    intensitasCahaya[ ] = {0.9f, 0.9f, 0.9f, 1.0f};
	GLfloat    posisiCahaya[ ]={2.0f,2.0f,2.0f, 0.0f};
	glLightfv(GL_LIGHT0, GL_POSITION, posisiCahaya);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, intensitasCahaya);

	GLfloat    bahan_ambient[ ]= {1.0f, 1.0f, 0.0f, 1.0f};
	GLfloat    bahan_diffuse[ ] = {0.6f, 1.0f, 0.0f, 1.0f};
	GLfloat    bahan_specular[ ] = {0.0f, 0.0f, 1.0f, 1.0f};
	GLfloat    bahan_shininess[ ] = {90.0f};

	GLfloat    bahan_ambient1[ ]= {1.0f, 0.0f, 0.0f, 1.0f};
	GLfloat    bahan_diffuse1[ ] = {1.0f, 0.0f, 0.0f, 1.0f};
	GLfloat    bahan_specular1[ ] = {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat    bahan_shininess1[ ] = {90.0f};

	GLfloat    bahan_ambient2[ ]= {0.0f, 1.0f, 0.0f, 1.0f};
	GLfloat    bahan_diffuse2[ ] = {0.0f, 1.0f, 0.0f, 1.0f};
	GLfloat    bahan_specular2[ ] = {0.0f, 1.0f, 0.0f, 1.0f};
	GLfloat    bahan_shininess2[ ] = {90.0f};
	
    GLfloat    bahan_ambient3[ ]= {0.0f, 0.0f, 1.0f, 1.0f};
	GLfloat    bahan_diffuse3[ ] = {0.0f, 0.0f, 1.0f, 1.0f};
	GLfloat    bahan_specular3[ ] = {0.0f, 0.0f, 1.0f, 1.0f};
	GLfloat    bahan_shininess3[ ] = {90.0f};
	
	GLfloat    bahan_ambient4[ ]= {1.0f, 1.0f, 0.0f, 1.0f};
	GLfloat    bahan_diffuse4[ ] = {1.0f, 1.0f, 0.0f, 1.0f};
	GLfloat    bahan_specular4[ ] = {1.0f, 1.0f, 0.0f, 1.0f};
	GLfloat    bahan_shininess4[ ] = {90.0f};	
	/* register window class */
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor (NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) GetStockObject (BLACK_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "TF-UAJY";
    RegisterClass (&wc);

    /* create main window */
    hWnd = CreateWindow (
      "TF-UAJY", "Teapot", 
      WS_CAPTION | WS_POPUPWINDOW | WS_VISIBLE,
      0, 0, 800, 600,
      NULL, NULL, hInstance, NULL);

    /* enable OpenGL for the window */
    EnableOpenGL (hWnd, &hDC, &hRC);
    
    
    //******************
    // Awal kode yang diambil dari bukunya Suyoto
    Inisialisasi(800, 600);
    // Akhir kode yang diambil dari bukunya Suyoto
    //******************
    
    
    /* program main loop */
    while (!bQuit)
    {
        /* check for messages */
        if (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage (&msg);
                DispatchMessage (&msg);
            }
        }
        else
        {
            /* OpenGL animation code goes here */
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            
            // Gambar meja
            
    DrawTable();
    DrawWalls();
    DrawChair(); 
	DrawFloor(); 
	      
            //******************
            // Awal kode yang diambil dari bukunya Suyoto
            //teapot
            glMaterialfv(GL_FRONT,GL_AMBIENT, bahan_ambient);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular);
			glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess);
            glPushMatrix( );
        		glTranslatef (-0.8f, -0.9f, -5.0);
        		glRotatef (10, 1, 0, 0);
        		glScalef (0.4, 0.4, 0.4);
        		glutSolidTeapot(0.8f );
        	glPopMatrix( );
        	
        	//torus1
            glMaterialfv(GL_FRONT,GL_AMBIENT, bahan_ambient1);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse1);
			glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular1);
			glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess1);        
            glPushMatrix( );
        		glTranslatef (1.0, -0.9, -5.0);
        		glRotatef (90, 1, 0, 0);
        		glScalef (0.4, 0.4, 0.4);
        		glutSolidTorus(0.3f, 0.8f, 50, 50);
        	glPopMatrix( );
        	glFlush ( );
        	
        	//torus2
            glMaterialfv(GL_FRONT,GL_AMBIENT, bahan_ambient2);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse2);
			glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular2);
			glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess3);        
            glPushMatrix( );
        		glTranslatef (1.0, -0.7, -5.0);
        		glRotatef (90, 1, 0, 0);
        		glScalef (0.3, 0.3, 0.3);
        		glutSolidTorus(0.3f, 0.8f, 50, 50);
        	glPopMatrix( );
        	glFlush ( );
        	
        	//torus3
            glMaterialfv(GL_FRONT,GL_AMBIENT, bahan_ambient3);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, bahan_diffuse3);
			glMaterialfv(GL_FRONT, GL_SPECULAR, bahan_specular3);
			glMaterialfv(GL_FRONT, GL_SHININESS, bahan_shininess3);        
            glPushMatrix( );
        		glTranslatef (1.0, -0.55, -5.0);
        		glRotatef (90, 1, 0, 0);
        		glScalef (0.2, 0.2, 0.2);
        		glutSolidTorus(0.3f, 0.8f, 50, 50);
        	glPopMatrix( );
        	glFlush ( );
        	
            
            // Akhir kode yang diambil dari bukunya Suyoto
            //******************
            
            SwapBuffers (hDC);
        }
    }

    /* shutdown OpenGL */
    DisableOpenGL (hWnd, hDC, hRC);

    /* destroy the window explicitly */
    DestroyWindow (hWnd);

    return msg.wParam;
}


/********
 * Window Procedure
 *
 ********/

LRESULT CALLBACK 
WndProc (HWND hWnd, UINT message,
         WPARAM wParam, LPARAM lParam)
{

    switch (message)
    {
    case WM_CREATE:
        return 0;
    case WM_CLOSE:
        PostQuitMessage (0);
        return 0;

    case WM_DESTROY:
        return 0;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_ESCAPE:
            PostQuitMessage(0);
            return 0;
        }
        return 0;

    default:
        return DefWindowProc (hWnd, message, wParam, lParam);
    }
}


/*******
 * Enable OpenGL
 *
 *******/

void
EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC)
{
    PIXELFORMATDESCRIPTOR pfd;
    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC (hWnd);

    /* set the pixel format for the DC */
    ZeroMemory (&pfd, sizeof (pfd));
    pfd.nSize = sizeof (pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | 
      PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;
    iFormat = ChoosePixelFormat (*hDC, &pfd);
    SetPixelFormat (*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext( *hDC );
    wglMakeCurrent( *hDC, *hRC );

}


/******
 * Disable OpenGL
 *
 ******/

void
DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent (NULL, NULL);
    wglDeleteContext (hRC);
    ReleaseDC (hWnd, hDC);
}
