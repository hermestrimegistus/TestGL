#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<stdio.h>
#pragma comment(lib,"glfw3dll")
#pragma comment(lib,"opengl32")
class GLContext
{
};
int main()
{
  if(!glfwInit()){
    fprintf(stdout,"Error\n");
    glfwTerminate();
    return 1;
  }
  GLFWwindow* window = glfwCreateWindow(800,800,"MM",NULL,NULL);
  glfwMakeContextCurrent(window);
  while(!glfwWindowShouldClose(window)){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f,0.4f,0.0f,1.0f);
    glfwPollEvents();
    glfwSwapBuffers(window);
  }
  glfwTerminate();
  return 0;
}
