#include <stdio.h>

int main(){
   int width, height, slotVazios, x1, x2, y1, y2, xMenor, xMaior, yMenor, yMaior, subpartes, i,j, k, board[550][550];
   scanf( "%i%i%i", &width, &height, &subpartes );
   while( height != 0 ){
      slotVazios = width * height;
      for( i = 0; i < width; i++) {
         for( j = 0; j < height; j++) {
            board[i][j] = 0;
        }
      }
      for(i = 0; i < subpartes; i++) {
         scanf( "%i%i%i%i", &x1, &y1, &x2, &y2);
         if( x1 <= x2 ){
            xMenor = x1;
            xMaior = x2;
         }
         else{
            xMenor = x2;
            xMaior = x1;
         }
         if( y1 <= y2 ){
            yMenor = y1;
            yMaior = y2;
         }
         else{
            yMenor = y2;
            yMaior = y1;
         }
         for(j = xMenor; j<= xMaior; j++  ){
            for( k = yMenor; k <= yMaior; k++ ){
               if( board[j-1][k-1] == 0 ){
                  board[j-1][k-1] = 1;
                  slotVazios--;
               }
            }
         }
      }

      switch( slotVazios ){
         case 0:
            printf( "There is no empty spots.\n" );
            break;
         case 1:
            printf( "There is one empty spot.\n" );
            break;
         default:
            printf( "There are %i empty spots.\n", slotVazios );
            break;
      }

      scanf( "%i%i%i", &width, &height, &subpartes );
   }


   return 0;
}
