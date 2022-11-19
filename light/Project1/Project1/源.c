#include <stdio.h>


int main() {
    float red = 1;
    float green = 1;
    float blue = 1;
    int flag = 0;
    int redLightness = 0;
    int blueLightness = 0;
    int greenLightness = 0;
    char command;
    enum LIGHTCOLOR
    {
        RED = 1, GREEN, BLUE
    };

    while (1) {
            printf("please input command;\n");
            command = getchar();
            
            switch (command) {
            case 'R':
                flag = RED;
                printf("switch to red light\n");
                break;

            case 'G':
                flag = GREEN;
                printf("switch to green light\n");
                break;

            case 'B':
                flag = BLUE;
                printf("switch to blue light\n");
                break;

            case '+'://0 on 1 off
                if (flag == RED && redLightness < 100) {
                    red = red - 0.1;
                    redLightness = redLightness + 10;
                }
                else if (flag == GREEN && greenLightness < 100) {
                    green = green - 0.1;
                    greenLightness = greenLightness + 10;
                }
                else if (flag == BLUE && blueLightness < 100)
                {
                    blue = blue - 0.1;
                    blueLightness = blueLightness + 10;
                }
                else
                {
                    printf("ERROR:Please select color or lightness is max\n");
                }
                printf("red lightness:%%%d , green lightness:%%%d ,blue lightness:%%%d\n", redLightness, greenLightness, blueLightness);
                break;

            case'-'://0 on 1 off
                if (flag == RED && redLightness > 0) {
                    red = red + 0.1;
                    redLightness = redLightness - 10;
                }
                else if (flag == GREEN && greenLightness > 0) {
                    green = green + 0.1;
                    greenLightness = greenLightness - 10;
                }
                else if (flag == BLUE && blueLightness > 0)
                {
                    blue = blue + 0.1;
                    blueLightness = blueLightness - 10;
                }
                else
                {
                    printf("ERROR:Please select color or color is minium\n");
                }

                printf("red lightness:%%%d , green lightness:%%%d ,blue lightness:%%%d\n", redLightness, greenLightness, blueLightness);
                break;

            case 'd'://0 on 1 off
                red = 1;
                blue = 1;
                green = 1;
                redLightness = 0;
                blueLightness = 0;
                greenLightness = 0;

                printf("Case d turn off all\n");
                break;

            case'l'://0 on 1 off
                red = 0;
                blue = 0;
                green = 0;
                redLightness = 100;
                blueLightness = 100;
                greenLightness = 100;
                printf("Case l turn on all\n");
                break;

            default:
                printf("Please input correct command\n");
            }
            char tmp = getchar();
        }
    return;
    }

