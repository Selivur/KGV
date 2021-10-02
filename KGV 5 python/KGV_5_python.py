from OpenGL.GLUT import *
from OpenGL.GL import *
from OpenGL.GLU import *
import pygame
from pygame.locals import *
colors= [[0.0,0.0,0.0,0.7],[1.0,0.0,0.0,0.7],[1.0,1.0,0.0,0.7],
         [0.0,1.0,1.0,0.7],[1.0,1.0,0.0,0.7],[0.0,0.0,1.0,0.7],
         [1.0,0.0,1.0,0.7],[0.0,1.0,0.0,0.7],[0.0,1.0,0.0,0.7],
         [0.0,1.0,0.0,0.7],[0.0,1.0,0.0,0.7],[0.0,1.0,0.0,0.7]]


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
def light():
    glEnable(GL_LIGHTING)
    glEnable(GL_LIGHT0)
    glLight(GL_LIGHT0, GL_POSITION, (4,0, 3, 0))
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE)
    glEnable(GL_COLOR_MATERIAL)                        
def Cube():
        glBegin(GL_QUADS)
        glColor4fv(colors[3])
        glTexCoord2f(1.0, 0.0)
        glVertex3f(-1.0, -1.0, 1.0)
        glTexCoord2f(1.0, 1.0)
        glVertex3f(-1.0, 1.0, 1.0)
        glTexCoord2f(0.0, 1.0)
        glVertex3f(-1.0, 1.0, -1.0)
        glTexCoord2f(0.0, 0.0)
        glVertex3f(-1.0, -1.0, -1.0)
        glColor4fv(colors[3])
        glTexCoord2f(1.0, 0.0)
        glVertex3f(-1.0, -1.0,  1.0)
        glTexCoord2f(1.0, 1.0)
        glVertex3f(1.0, -1.0,  1.0)
        glTexCoord2f(0.0, 1.0)
        glVertex3f(1.0,  1.0,  1.0)
        glTexCoord2f(0.0, 0.0)
        glVertex3f(-1.0,  1.0,  1.0)
        glColor4fv(colors[3])
        glTexCoord2f(1.0, 0.0)
        glVertex3f(-1.0, -1.0, -1.0)
        glTexCoord2f(1.0, 1.0)
        glVertex3f(-1.0,  1.0, -1.0)
        glTexCoord2f(0.0, 1.0)
        glVertex3f(1.0,  1.0, -1.0)
        glTexCoord2f(0.0, 0.0)
        glVertex3f(1.0, -1.0, -1.0)
        glColor4fv(colors[3])
        glTexCoord2f(1.0, 0.0)
        glVertex3f(-1.0,  1.0, -1.0)
        glTexCoord2f(1.0, 1.0)
        glVertex3f(-1.0,  1.0,  1.0)
        glTexCoord2f(0.0, 1.0)
        glVertex3f(1.0,  1.0,  1.0)
        glTexCoord2f(0.0, 0.0)
        glVertex3f(1.0,  1.0, -1.0)
        glColor4fv(colors[3])
        glTexCoord2f(1.0, 0.0)
        glVertex3f(-1.0, -1.0, -1.0)
        glTexCoord2f(1.0, 1.0)
        glVertex3f(1.0, -1.0, -1.0)
        glTexCoord2f(0.0, 1.0)
        glVertex3f(1.0, -1.0,  1.0)
        glTexCoord2f(0.0, 0.0)
        glVertex3f(-1.0, -1.0,  1.0)
        glColor4fv(colors[3])       
        glTexCoord2f(1.0, 0.0)
        glVertex3f(1.0, -1.0, -1.0)        
        glTexCoord2f(1.0, 1.0)
        glVertex3f(1.0,  1.0, -1.0)        
        glTexCoord2f(0.0, 1.0)
        glVertex3f(1.0,  1.0,  1.0)        
        glTexCoord2f(0.0, 0.0)
        glVertex3f(1.0, -1.0,  1.0)
        glEnd()
        glMatrixMode(GL_TEXTURE)
        glTexCoord2f(1.0, 0.0)
        glVertex3f(1.0, -1.0, -1.0)
        glTexCoord2f(1.0, 1.0)
        glVertex3f(1.0,  1.0, -1.0)   
        glTexCoord2f(0.0, 1.0)
        glVertex3f(1.0,  1.0,  1.0)       
        glTexCoord2f(0.0, 0.0)
        glVertex3f(1.0, -1.0,  1.0)
        glRotatef(2,0,0,3)
        glPushMatrix()        
        glPopMatrix()
        glMatrixMode(GL_MODELVIEW)

def main():
    pygame.init()
    display = (900,700)
    screen = pygame.display.set_mode(
    display, pygame.DOUBLEBUF | pygame.OPENGL | pygame.OPENGLBLIT)
    glEnable (GL_ALPHA_TEST)
    glEnable (GL_BLEND)
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)
    loadTexture()
    #light()
    #glOrtho(-10.0,10.0,-10.0,10.0,-5.0,5.0)
    gluPerspective(45, (display[0]/display[1]), 0.1, 50.0)
    glEnable(GL_TEXTURE_2D)
    glEnableClientState(GL_TEXTURE_COORD_ARRAY)
    glEnable(GL_DEPTH_TEST)
    glDepthMask(GL_TRUE)
    glDepthFunc(GL_LEQUAL)
    glDepthRange(0.0, 1.0)
    glClearColor(0.0, 0.0, 0.0, 0.0)
    glClearDepth(1.0)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
   
    glTranslatef(0.0,0.0, -5)
    
    mx1=0
    my1=0
    
    while True:
        for event in pygame.event.get():
            if event.type == KEYDOWN and event.key == K_ESCAPE:
                exit()
            if event.type == pygame.QUIT:
                exit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:                   
                    glTranslatef(-0.5,0,0)
                if event.key == pygame.K_RIGHT:                   
                    glTranslatef(0.5,0,0)
                if event.key==pygame.K_UP:
                    glTranslatef(0,1,0)
                if event.key==pygame.K_DOWN:
                    glTranslatef(0,-1,0)
            if event.type==pygame.MOUSEBUTTONDOWN:
                if event.button==4:
                    glTranslatef(0,0,1.0)
                if event.button==5:
                    glTranslatef(0,0,-1.0)
                                          
            if pygame.mouse.get_pressed()[0]:
                    if event.type==pygame.MOUSEMOTION :
                            mx,my = pygame.mouse.get_pos()
                            mx=round(mx/10)
                            my=round(my/10)
                            print(mx,my)                           
                            if mx<mx1 and my<my1 or mx<mx1+1 and my<my1+1 or mx<mx1-1 and my<my1-1 :
                                    glRotatef(5, 0, -3, -1)
                            if mx>mx1 and my>my1 or mx>mx1-1 and my>my1-1 or mx>mx1+1 and my>my1+1 :
                                    glRotatef(5, 0, 3, 1)
                            if mx==mx1 and my>=my1 or mx==mx1-1 and my>=my1:
                                    glRotatef(5,3,0,1)
                            if mx==mx1 and my<=my1 or mx==mx1-1 and my<=my1:
                                    glRotatef(5,-3,0,-1)
                            mx1=mx
                            my1=my           
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
        Cube()
        pygame.display.flip()
        pygame.time.wait(10)

main()
