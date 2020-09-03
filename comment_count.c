#include <stdio.h>

/*abcdef*/

int main(int argc, char *argv[])
{

	//44 characters total including this one

    int count = 0;
    int string;
    int x;
    int c;
    
    FILE *file = fopen(argv[1], "r" );
    
    while((string = fgetc(file))!= EOF){
        
        if(string == '/' && (string = getc(file)) == '*'){
            
            c = 1;

            }
        
         if(string == '/' && (string = getc(file)) == '/'){
            c = 1;
        }
        
        if(string == '*' && (string = getc(file)) == '/'){
            c = 0;
            
        }
        
        
        if(c == 1){
        count++;
        }

        }
        
        fseek(file, 0, 0);
        
        while ((string = fgetc(file)) != EOF){
        if (string  ==  '/')
        {
            if ((string = fgetc(file))  ==  '/')
            {
                x = 1;
                }
        }
        
            if(x == 1 && string == '\n'){
                count-=1;
                x = 0;
                
            }
            
            
            if(x == 1){
                count++;
            }
        
        
        }
        
    
    fclose(file);
    printf("The total number of commented characters is %d\n", count);
    return 0;
}