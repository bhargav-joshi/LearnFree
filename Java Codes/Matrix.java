import java.io.*;
class Matrix{
	public static void main(String[] args) throws IOException {
	InputStreamReader a = new InputStreamReader(System.in);
	BufferedReader b = new BufferedReader(a);
	boolean k1=true;
	int first[][]=new int[3][3];
	int second[][]=new int[3][3];
	int third[][]=new int[3][3];
	int fourth[][]=new int[3][3];
	int temp[][]=new int [3][3];
    int sum=0;
	while(k1){
		System.out.println("CASE-1: CREATE first 2-D array");
		System.out.println("CASE-2: DISPALY first 2-D array");
		System.out.println("CASE-3: ROW SUM");
		System.out.println("CASE-4: COL SUM");
		System.out.println("CASE-5: LEFT DIAGONAL SUM");
		System.out.println("CASE-6: RIGHT DIAGONAL SUM");
		System.out.println("CASE-7: INNER SUM");
		System.out.println("CASE-8: OUTER SUM");
		System.out.println("CASE-9: TRANSPOSE");
		System.out.println("CASE-10: MIRROR");
		System.out.println("CASE-11: SEARCH NUMBER");
		System.out.println("CASE-12: ROW SORT");
		System.out.println("CASE-13: COLUMN SORT");
		System.out.println("CASE-14: COMPLETE SORT");
		System.out.println("CASE-15: CREATE SECOND 2-D ARRAY");
		System.out.println("CASE-16: DISPLAY SECOND 2-D ARRAY");
		System.out.println("CASE-17: ADDITION OF 2-D ARRAYS");
		System.out.println("CASE-18: DISPLAY THIRD 2-D ARRAY AFTER ADDITION");
		System.out.println("CASE-19: MULTIPLICATION OF ARRAY");
		System.out.println("CASE-20: DISPLAY FOURTH AFTER MULTIPLICATION");
		System.out.println("CASE-21: EXIT ");
		int j = Integer.parseInt(b.readLine());
		switch(j){
			case 1:
			System.out.println("enter numbers");
            for (int r=0;r<3 ;r++ ) {
            	for (int c=0;c<3;c++ ) {
            		System.out.println("enter element");
            		first[r][c]=Integer.parseInt(b.readLine());
            	}
            }
			break;
			case 2:
			for (int r=0;r<3 ;r++ ) {
            	for (int c=0;c<3;c++ ) {
            		System.out.print(first[r][c]+"\t");
            	}
            		System.out.println();

            }
			break;
			case 3:
			 sum=0;
			for (int r=0;r<3 ;r++ ) {
            	for (int c=0;c<3;c++ ) {
            		sum=sum+first[r][c];
            		System.out.print(first[r][c]+"\t");
            	}
            		System.out.print("=>"+sum+"\t");
            		sum=0;
            		System.out.println();

            }
			break;
			case 4:
			int sum1[]=new int[3];
			for (int r=0;r<3 ;r++ ) {
            	for (int c=0;c<3;c++ ) {
            		sum1[c]=sum1[c]+first[r][c];
            		System.out.print(first[r][c]+"\t");
            	}
            		System.out.println();

            	}
            		System.out.println("_"+"\t"+"_"+"\t"+"_");  	
            	for (int r=0;r<3 ;r++ ) {
            		System.out.print(sum1[r]+"\t");
            		
            	}
            		System.out.println();

			break;
			case 5:
			 sum=0;
			for (int r=0;r<3 ;r++ ) {
            	for (int c=0;c<3;c++ ) {
            		if (r==c) {
            		sum=sum+first[r][c];	
            		}
            		System.out.print(first[r][c]+"\t");
            	}
            		System.out.println();
            }
            System.out.print("sum is <=> "+sum+"\t");
			break;
           case 6:
           sum=0;
			for (int r=0;r<3 ;r++ ) {
            	for (int c=0;c<3;c++ ) {
            		if (r-c==2||r-c==-2) {
            		sum=sum+first[r][c];	
            		}
            		System.out.print(first[r][c]+"\t");
            	}
            		System.out.println();
            }
            sum=sum+first[1][1];
            System.out.print("sum is <=> "+sum+"\t");
           break;
           case 7:
            sum=0;
			for (int r=0;r<3 ;r++ ) {
            	for (int c=0;c<3;c++ ) {
            		if (r-c==1||r-c==-1) {
            		sum=sum+first[r][c];	
            		}
            		System.out.print(first[r][c]+"\t");
            	}
            		System.out.println();
            }
            System.out.println("sum is <=> "+sum+"\t");
           break;
           case 8:
            sum=0;
			for (int r=0;r<3 ;r++ ) {
            	for (int c=0;c<3;c++ ) {
            		
            		System.out.print(first[r][c]+"\t");
            	}
            		System.out.println();
            }
            sum=sum +first[0][0]+first[0][2]+first[2][0]+first[2][2];
            System.out.print("sum is <=> "+sum+"\t");
           break;
           case 9:
             for (int r=0;r<3 ;r++ ) {
            	for (int c=0;c<3;c++ ) {
            		
            	     temp[r][c]=first[c][r];
            	}}
            		System.out.println("TRANSPOSED succesfully");
            
            for (int r=0;r<3 ;r++ ) {
            	for (int c=0;c<3;c++ ) {
            		
            		first[r][c]=temp[r][c];
            	}
            		System.out.println();
            }      
           break;
           case 10:
           for (int r=0;r<3 ;r++ ) {
            	for (int c=0;c<3;c++ ) {
                       if(c==2){
            		System.out.print(first[r][c]+" "+"|"+" ");
            		for (int h=3;h>0 ;h-- ) {
            		System.out.print(first[r][h-1]+"\t");
            		continue;         			
            		}

                       }   
            		else 
            			System.out.print(first[r][c]+"\t");
            	}
            		System.out.println();

            }
            for (int r=0;r<3 ;r++ ) {
            	for (int c=0;c<3;c++ ) {
            		
            		temp[r][c]=first[r][c];
            	}
            		System.out.println();
            }
            for (int r=0;r<6 ;r++ ){
            		System.out.print("_"+"\t");

            }
            		System.out.println();

            for (int r=0;r<3 ;r++ ) {
            	for (int c=0;c<3;c++ ) {
                       if(c==2){
            		System.out.print(temp[r][c]+" "+"|"+" ");
            		for (int h=3;h>0 ;h++ ) {
            		System.out.print(temp[r][h-1]+"\t");
            		continue;         			
            		}

                       }   
            		else 
            			System.out.print(temp[r][c]+"\t");
            	}
            		System.out.println();

            }

           break;
           case 11:
            		System.out.println("enter number you want to search");
            		int serc = Integer.parseInt(b.readLine());
            		 sum=0;
            		for (int r=0;r<3 ;r++ ) {
            	for (int c=0;c<3;c++ ) {
                  if (serc==first[r][c]) {
                  	  sum=sum+1;
                  }
            	}
            }
            if (sum==0) {
            		System.out.println("not found"); 	
            }
            else{
            		System.out.println("number found and present "+sum+"times"); 	
            }
           break;
           case 12:
            		System.out.println("row sorted"); 	
                    for (int r=0;r<3 ;r++ ) {
            	for (int c=0;c<3;c++ ) {
            		for (int h=c+1;h<3 ;h++ ) {
                               int tempo;
            			if(first[r][c]>first[r][h])
                              { tempo=first[r][c];
                                first[r][c]=first[r][h];
                                first[r][h]=first[r][c];
                            }
            		}
            	}
            }      
           break;
           case 13:
            		System.out.println("COLUMN sorted"); 	
                    for (int r=0;r<3 ;r++ ) {

            	for (int c=0;c<3;c++ ) {
            		        for(int h=c+1;h<3;h++)
                               {int tempo;
            			if(first[c-1][r]>first[c][r])
                              { tempo=first[r][c];
                                first[r][c]=first[r][h];
                                first[r][h]=first[r][c];
            		}}
            	}
            }      
           break;
           case 14:
            		System.out.println("COMPLETELY sorted"); 	
                    for (int r=0;r<3 ;r++ ) {
            	for (int c=0;c<3;c++ ) {
            		for (int h=c+1;h<3 ;h++ ) {
                               int tempo;
            			if(first[r][c]>first[r][h])
                              { tempo=first[r][c];
                                first[r][c]=first[r][h];
                                first[r][h]=first[r][c];
                            }
            		}
            	}
            }    
             for (int r=0;r<3 ;r++ ) {

            	for (int c=0;c<3;c++ ) {
            		        for(int h=c+1;h<3;h++)
                               {int tempo;
            			if(first[c-1][r]>first[c][r])
                              { tempo=first[r][c];
                                first[r][c]=first[r][h];
                                first[r][h]=first[r][c];
            		}}
            	}
            }                 
           break;
           case 15:
           System.out.println("enter numbers");
            for (int r=0;r<3 ;r++ ) {
            	for (int c=0;c<3;c++ ) {
            		System.out.println("enter element");
            		second[r][c]=Integer.parseInt(b.readLine());
            	}
            }
           break;
           case 16:
           for (int r=0;r<3 ;r++ ) {
            	for (int c=0;c<3;c++ ) {
            		System.out.print(second[r][c]+"\t");
            	}
            		System.out.println();

            }
           break;
           case 17:
           for (int r=0;r<3 ;r++ ) {
            	for (int c=0;c<3;c++ ) {
            	//	System.out.print(second[r][c]+"\t");
            		third[r][c]=first[r][c]+second[r][c];
            	}
            }
            System.out.println("added succesfully");
           break;
           case 18:
           for (int r=0;r<3 ;r++ ) {
            	for (int c=0;c<3;c++ ) {
            		System.out.print(third[r][c]+"\t");
            	}
            		System.out.println();

            }
           break;
           case 19:
           //sum;
           for (int r=0;r<3 ;r++ ) {
            	for (int c=0;c<3;c++ ) {
            		fourth[r][c]=0;
            	    for (int k=0;k<3;k++ ) {
            	    	fourth[r][c]=fourth[r][c]+first[r][k]*second[k][c]; 
            	    }
            	}
            }
            		System.out.println("multiplied succesfully");
           break;
           case 20:
           for (int r=0;r<3 ;r++ ) {
            	for (int c=0;c<3;c++ ) {
            		System.out.print(fourth[r][c]+"\t");
            	}
            		System.out.println();

            }
           break;
           case 21:
           k1=false;
           break;
		}


	}

	}
}
