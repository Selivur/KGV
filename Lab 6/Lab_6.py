import pygame
from pygame.locals import *
from OpenGL.GLUT import *
from OpenGL.GL import *
from OpenGL.GLU import *
from pygame.locals import *
colors= [[0.0,0.0,0.0,0.5],[1.0,0.0,0.0,0.5],[1.0,1.0,0.0,0.5],
         [0.0,1.0,1.0,0.5],[1.0,1.0,0.0,0.5],[0.0,0.0,1.0,0.5],
         [1.0,0.0,1.0,0.5],[0.0,1.0,0.0,0.5],[0.0,1.0,0.0,0.5],
         [0.0,1.0,0.0,0.5],[0.0,1.0,0.0,0.5],[0.0,1.0,0.0,0.5]]
verticies = (
    (1, -1, -1),
    (1, 1, -1),
    (-1, 1, -1),
    (-1, -1, -1),
    (1, -1, 1),
    (1, 1, 1),
    (-1, -1, 1),
    (-1, 1, 1)
    )

edges = (
    (0,1),
    (0,3),
    (0,4),
    (2,1),
    (2,3),
    (2,7),
    (6,3),
    (6,4),
    (6,7),
    (5,1),
    (5,4),
    (5,7)
    )


def loadTexture():
    textureSurface = pygame.image.load('copy.jpg')
    textureData = pygame.image.tostring(textureSurface, "RGBA", 1)
    width = textureSurface.get_width()
    height = textureSurface.get_height()

    glEnable(GL_TEXTURE_2D)
    texid = glGenTextures(1)

    glBindTexture(GL_TEXTURE_2D, texid)
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height,
                 0, GL_RGBA, GL_UNSIGNED_BYTE, textureData)

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT)
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT)
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST)
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST)

    return texid

def reshape(w,h):
    glViewport(0,0,w,h)
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    glOrtho(-10.0,10.0,-10.0,10.0,-10.0,10.0)
    glMatrixMode(GL_MODELVIEW)
    glLoadIdentity()
def svet():
    
    light0_pos=[1.0,2.0,3.0,1.0]
    light0_dir=[1.0,2.0,3.0,0.0]
    ambient0=[1.0,0.0,0.0,1.0]
    diffuse0=[1.0,0.0,0.0,1.0]
    specular0=[1.0,1.0,1.0,1.0]
    glob_am=[0.1,0.1,0.1,1.0]
    glEnable(GL_LIGHTING)
    glEnable(GL_LIGHT0)
    
    glLightfv(GL_LIGHT0,GL_POSITION,light0_pos)
    glLightfv(GL_LIGHT0,GL_AMBIENT,ambient0)
    glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuse0)
    glLightfv(GL_LIGHT0,GL_SPECULAR,specular0)
    glMaterialfv(GL_FRONT, GL_DIFFUSE, (1.0,1.0,1.0,1.0))
    glMaterialfv(GL_BACK, GL_DIFFUSE, (1.0,1.0,1.0,1.0))
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,glob_am)
    glShadeModel(GL_SMOOTH)
                            
def Cube():
   
        glBegin(GL_QUADS)
        glNormal3f(0.0, 0.0, 1.0)
        glTexCoord2f(0.0, 0.0)
        glVertex3f(-1.0, -1.0, 1.0)
        glTexCoord2f(1.0, 0.0)
        glVertex3f(1.0, -1.0, 1.0)
        glTexCoord2f(1.0, 1.0)
        glVertex3f(1.0, 1.0, 1.0)
        glTexCoord2f(0.0, 1.0)
        glVertex3f(-1.0, 1.0, 1.0)

        
        glNormal3f(0.0, 0.0, -1.0)
        glTexCoord2f(1.0, 0.0)
        glVertex3f(-1.0, -1.0, -1.0)
        glTexCoord2f(1.0, 1.0)
        glVertex3f(-1.0, 1.0, -1.0)
        glTexCoord2f(0.0, 1.0)
        glVertex3f(1.0, 1.0, -1.0)
        glTexCoord2f(0.0, 0.0)
        glVertex3f(1.0, -1.0, -1.0)

        
        glNormal3f(0.0, 1.0, 0.0)
        glTexCoord2f(0.0, 1.0)
        glVertex3f(-1.0, 1.0, -1.0)
        glTexCoord2f(0.0, 0.0)
        glVertex3f(-1.0, 1.0, 1.0)
        glTexCoord2f(1.0, 0.0)
        glVertex3f(1.0, 1.0, 1.0)
        glTexCoord2f(1.0, 1.0)
        glVertex3f(1.0, 1.0, -1.0)

        
        glNormal3f(0.0, -1.0, 0.0)
        glTexCoord2f(0.0, 0.0)
        glVertex3f(-1.0, -1.0, -1.0)
        glTexCoord2f(1.0, 0.0)
        glVertex3f(1.0, -1.0, -1.0)
        glTexCoord2f(1.0, 1.0)
        glVertex3f(1.0, -1.0, 1.0)
        glTexCoord2f(0.0, 1.0)
        glVertex3f(-1.0, -1.0, 1.0)      
        glNormal3f(1.0, 0.0, 0.0)
        glTexCoord2f(1.0, 0.0)
        glVertex3f(1.0, -1.0, -1.0)
        glTexCoord2f(1.0, 1.0)
        glVertex3f(1.0, 1.0, -1.0)
        glTexCoord2f(0.0, 1.0)
        glVertex3f(1.0, 1.0, 1.0)
        glTexCoord2f(0.0, 0.0)
        glVertex3f(1.0, -1.0, 1.0)
        glNormal3f(-1.0, 0.0, 0.0)
        glTexCoord2f(1.0, 0.0)
        glVertex3f(-1.0, -1.0, 1.0)
        glTexCoord2f(1.0, 1.0)
        glVertex3f(-1.0, 1.0, 1.0)
        glTexCoord2f(0.0, 1.0)
        glVertex3f(-1.0, 1.0, -1.0)
        glTexCoord2f(0.0, 0.0)
        glVertex3f(-1.0, -1.0, -1.0)
        glEnd()

                
           


def main():
    pygame.init()
    screen = (800, 600)
    display = pygame.display.set_mode(screen, DOUBLEBUF|OPENGL)
    #glFrustum(-0.8, 0.8, -0.8, 0.8, 0.8, 15.0)
    #glFrustum(-0.8, 0.8, -0.8, 0.8, 1.0, 0.8)
    glEnable(GL_BLEND)
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)
    glMatrixMode(GL_PROJECTION)
    gluPerspective(45, (screen[0] / screen[1]), 0.1, 500)
    #glOrtho(-10,10,-10, 10, 5,10)
    #gluLookAt(5,5,5,0,0,0,0,1,0)
    button_down = False
    loadTexture()
    glEnable(GL_DEPTH_TEST)
    glMatrixMode(GL_MODELVIEW)
    modelMatrix = glGetFloatv(GL_MODELVIEW_MATRIX)

    dd=1
    cc=1
    mx1 = 0
    my1 = 0
    ambient = (0.5, 0.5, 1.0, 1.0)
    while True:
        glPushMatrix()
        glLoadIdentity()
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    cc=cc*(-1)
                    glEnable(GL_LIGHTING)
                    #glTranslatef(-0.5, 0, 0)
                if event.key == pygame.K_RIGHT:
                    dd=dd*(-1)
                    glEnable(GL_LIGHT0)
                    glLight(GL_LIGHT0, GL_POSITION, pos)
                    #glTranslatef(0.5, 0, 0)
                if event.key == pygame.K_UP:
                    #glTranslatef(0, 1, 0)
                    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambient)
                if event.key == pygame.K_DOWN:
                    glTranslatef(0, -1, 0)
            if event.type == pygame.MOUSEBUTTONDOWN:
                if event.button == 4:
                    glTranslatef(0, 0, 1.0)
                if event.button == 5:
                    glTranslatef(0, 0, -1.0)

            if pygame.mouse.get_pressed()[0]:
                if event.type == pygame.MOUSEMOTION:
                    mx, my = pygame.mouse.get_pos()
                    mx = round(mx / 10)
                    my = round(my / 10)
                    print(mx, my)
                    if mx < mx1 and my < my1 or mx < mx1 + 1 and my < my1 + 1 or mx < mx1 - 1 and my < my1 - 1:
                        glRotatef(5, 0, -3, -1)
                    if mx > mx1 and my > my1 or mx > mx1 - 1 and my > my1 - 1 or mx > mx1 + 1 and my > my1 + 1:
                        glRotatef(5, 0, 3, 1)
                    if mx == mx1 and my >= my1 or mx == mx1 - 1 and my >= my1:
                        glRotatef(5, 3, 0, 1)
                    if mx == mx1 and my <= my1 or mx == mx1 - 1 and my <= my1:
                        glRotatef(5, -3, 0, -1)
                    mx1 = mx
                    my1 = my

        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        glMultMatrixf(modelMatrix)
        modelMatrix = glGetFloatv(GL_MODELVIEW_MATRIX)

        glLoadIdentity()
        glTranslatef(0, 0, -5)
        
        #glEnable(GL_LIGHTING)
        #glEnable(GL_LIGHT0)
        #glEnable(GL_LIGHT1)
        glShadeModel(GL_SMOOTH)

        dif = (1.0, 1.0, 1.0, 1.0)
        pos = (41, 41, 51, 1)
        pos2=(-10, 10, 50, 1)

        
        
        #glLight(GL_LIGHT0, GL_POSITION, pos)
        #if dd==1:
        #glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambient)
       
        #if cc==1:
        #svet()
        #glLight(GL_LIGHT1, GL_POSITION, pos2)
        #glEnable(GL_COLOR_MATERIAL)
        #glColorMaterial(GL_FRONT, GL_AMBIENT)
        mat_specular = (1, 1, 1)
        #glMaterial(GL_FRONT, GL_SPECULAR, mat_specular)
        #glMaterial(GL_FRONT_AND_BACK,GL_DIFFUSE,(1.0,0.0,0.0))
        glMultMatrixf(modelMatrix)
        
        Cube()

        glPopMatrix()
        pygame.display.flip()
        pygame.time.wait(10)
main()

