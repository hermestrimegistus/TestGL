#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<stdio.h>
#include<string>
#pragma comment(lib,"glfw3dll")
#pragma comment(lib,"opengl32")
#pragma comment(lib,"glew32d")
class GLContext
{
};

void my_input_callback(GLFWwindow* window, int key,int scancode,int action,int mode)
{
  fprintf(stdout,"Got key %d\n",key);
  if(key == GLFW_KEY_ESCAPE){
    glfwSetWindowShouldClose(window,true);
  }
}
int main(int argc,char** argv)
{
  if(argc < 2) return 1;
  int width = atoi(*++argv);
  int height = atoi(*++argv);
  if(!glfwInit()){
    fprintf(stdout,"Error\n");
    glfwTerminate();
    return 1;
  }
  GLFWwindow* window = glfwCreateWindow(width,height,"MM",NULL,NULL);
  glfwMakeContextCurrent(window);
  glfwSetKeyCallback(window,my_input_callback);
  if(GLEW_OK != glewInit()){
    fprintf(stdout,"glewInit failed");
    glfwTerminate();
    return 1;
  }
  unsigned int vbo;
  glGenBuffers(1,&vbo);
  
  fprintf(stdout,"Got buffer %u\n",vbo);
  const GLubyte *f = glGetString(GL_VERSION);
  fprintf(stdout,"Version is %s\n",f);
  GLfloat t1 = glfwGetTime();
  GLfloat t2;
  GLfloat diff;
  GLfloat frameRate;
  int frames(0);
  while(!glfwWindowShouldClose(window)){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f,0.4f,0.0f,1.0f);
    glfwPollEvents();
    t2 = glfwGetTime();
    diff = t2-t1;
    frames++;
    if(diff > 0.25){
      frameRate = frames/diff;      
      glfwSetWindowTitle(window,std::to_string(frameRate).c_str());
      t1 = t2;
      frames = 0;
    }
    glfwSwapBuffers(window);
  }
  glfwTerminate();
  return 0;
}
