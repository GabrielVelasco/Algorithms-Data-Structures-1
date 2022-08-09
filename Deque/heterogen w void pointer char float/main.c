#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queue.h"

void _print_float_char(void* data, int key){
    if(key)
        printf("%.2f ", *((float*)data) );
    else
        printf("%c ", *((char*)data) );
}

void _print_empty_msg(){
    printf("Empty! ");
}

int main(){
    Queue qu;
    int opc;
    float f_grade;
    char opc2, c_grade;;
    while(1){
        f_grade = -1;
        c_grade = '#';
        printf("\n0 - Create queue\n");
        printf("1 - Push back\n");
        printf("2 - Push front\n");
        printf("3 - Pop back\n");
        printf("4 - Pop front\n");
        printf("5 - Print queue\n");
        printf("6 - Get element by its position\n");
        printf("7 - Remove element\n");
        printf("Option: ");
        scanf("%d", &opc); getchar();

        /// optimizar, usar alloc_check etc....

        switch(opc){
            case 0:
                qu = _create_queue();
                printf("Queue created!\n");
                break;

            case 1:
                printf("Push back, (F) float, (C) character: ");
                scanf("%c", &opc2);

                if(opc2 == 'F'){ /// vai adicionar um float a lista
                    printf("Type a float: ");
                    scanf("%f", &f_grade);
                    if(_push_back(qu, '0', f_grade, true))
                        printf("Push back success!\n");
                    else
                        printf("Error while inserting!\n");

                }else if(opc2 == 'C'){
                    printf("Type a char: "); getchar();
                    scanf("%c", &c_grade);
                    if(_push_back(qu, c_grade, 0.0, false))
                        printf("Push back success!\n");
                    else
                        printf("Error while inserting!\n");

                }else
                    printf("Invalid option!\n");
                break;

            case 2:
                printf("Push front, (F) float, (C) character: ");
                scanf("%c", &opc2);

                if(opc2 == 'F'){ /// vai adicionar um float a lista
                    printf("Type a grade: ");
                    scanf("%f", &f_grade);
                    if(_push_front(qu, '0', f_grade, true))
                        printf("Push front success!\n");
                    else
                        printf("Error while inserting!\n");

                }else if(opc2 == 'C'){
                    printf("Type a grade: "); getchar();
                    scanf("%c", &c_grade);
                    if(_push_front(qu, c_grade, 0, false))
                        printf("Push front success!\n");
                    else
                        printf("Error while inserting!\n");

                }else
                    printf("Invalid option!\n");
                break;

            case 3:
                if(_pop_back(qu, &c_grade, &f_grade)){
                    if(f_grade != -1)
                        printf("Pop back success, [%.2f] removed!\n", f_grade);
                    else if(c_grade != '#')
                        printf("Pop back success, [%c] removed!\n", c_grade);
                }else
                    printf("Pop back error!\n");
                break;


            case 4:
                if(_pop_front(qu, &c_grade, &f_grade)){
                    if(f_grade != -1)
                        printf("Pop front success, [%.2f] removed!\n", f_grade);
                    else if(c_grade != '#')
                        printf("Pop front success, [%c] removed!\n", c_grade);
                }else
                    printf("Pop front error!\n");
                break;

            case 5:
                printf("{ ");
                _print(qu);
                printf("}\n");
                break;

            case 6:
                printf("Type a position (0-based): ");
                scanf("%d", &opc);
                if(_get_elem(qu, opc, &c_grade, &f_grade)){
                    if(f_grade != -1)
                        printf("Element of index[%d] = %.2f\n", opc, f_grade);
                    else if(c_grade != '#')
                        printf("Element of index[%d] = %c\n", opc, c_grade);
                }else
                    printf("Invalid position!\n");
                break;

            case 7:
                printf("[F] to remove a float, [C] to remove a char: ");
                scanf("%c", &opc2);

                if(opc2 == 'F'){ /// remover um float
                    printf("Type a float: ");
                    scanf("%f", &f_grade);
                    if(_remove_elem(qu, '0', f_grade, true))
                        printf("[%.2f] removed!\n", f_grade);
                    else
                        printf("Element not found!\n");

                }else if(opc2 == 'C'){
                    printf("Type a char: "); getchar();
                    scanf("%c", &c_grade);
                    if(_remove_elem(qu, c_grade, 0, false))
                        printf("[%c] removed!\n", c_grade);
                    else
                        printf("Element not found!\n");

                }else
                    printf("Invalid option!\n");
                break;

            default:
                return 0;
        }
    }

    return 0;
}