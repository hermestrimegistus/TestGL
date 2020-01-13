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
int main()
{
  if(!glfwInit()){
    fprintf(stdout,"Error\n");
    glfwTerminate();
    return 1;
  }
  GLFWwindow* window = glfwCreateWindow(800,800,"MM",NULL,NULL);
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
  int frames(0);
  while(!glfwWindowShouldClose(window)){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f,0.4f,0.0f,1.0f);
    glfwPollEvents();
    t2 = glfwGetTime();
    diff += t2-t1;
    frames++;
    if(diff >= 1.0f){
      glfwSetWindowTitle(window,std::to_string(frames).c_str());
      frames = 0;
      t1 = t2;
      diff = 0;
    }
    glfwSwapBuffers(window);
  }
  glfwTerminate();
  return 0;
}
