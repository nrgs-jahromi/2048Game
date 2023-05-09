//in the name of god
#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;
int line,pier,a[20][20],b[20][20];
unsigned int score;
bool gaming=true;

void up(int a[20][20]);
void down(int a[20][20]);
void right(int a[20][20]);
void left(int a[20][20]);

int main()
{
     int i,j,y1=0,z1=0;
     score=0;
     cout<<"\n__________Wellcome to the game__________\n"<<endl;
    cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout<<"%                                                                        %\n";
    cout<<"%       %%%%%%%       %%%%%%%%%%      %%         %%      %%%%%%%%%%      %\n";
    cout<<"%      %%     %%     %%        %%     %%         %%     %%        %%     %\n";
    cout<<"%     %%       %%    %%        %%     %%         %%     %%        %%     %\n";
    cout<<"%             %%     %%        %%     %%         %%     %%        %%     %\n";
    cout<<"%           %%       %%        %%     %%%%%%%%%%%%%      %%%%%%%%%%      %\n";
    cout<<"%         %%         %%        %%                %%     %%        %%     %\n";
    cout<<"%       %%           %%        %%                %%     %%        %%     %\n";
    cout<<"%     %%             %%        %%                %%     %%        %%     %\n";
    cout<<"%    %%%%%%%%%%%%     %%%%%%%%%%                 %%      %%%%%%%%%%      %\n";
    cout<<"%                                                                        %\n";
    cout<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n\n\n\n\n";

     system("pause");
     system("cls");

     char name[30];

     srand(time(NULL));

     cout<<"(1) New game\n"<<"(2) Continue game\n"<<"(3) View the scoreboard\n";
     cout<<"Enter a number:\n";

     int x1,size;
     cin>>x1;
     system("pause");
     system("cls");

     if(x1==3){
            FILE*f;
            f=fopen("F:\\scoreboard.txt","r");
            if(f==NULL){
                cout<<"no record has been set yet!";
                exit(0);
            }

            int i = 0;
            while(!feof(f)){
                fread(&line,sizeof(int),1,f);
                fread(&pier,sizeof(int),1,f);
                fread(&name,sizeof(char),30,f);
                fread(&score,sizeof(int),1,f);


                if(feof(f)){
                    break;
                }
                      cout << ++i<<"\t" <<name<< "\t";
                      cout << score <<"\t";
                      cout << line<<"*"<<pier<<"\n";
            }
            fclose(f);


            cout<<"**ENTER 1 TO PLAY A NEW GAME!\n"<<"**ENTER 2 TO CONTINUE THE LAST GAME!";
            cin>>z1;



     }



      if(x1==2 || z1==2){
            FILE*fptr;
            fptr=fopen("F:\\mab2048.txt","r");
            if(fptr==NULL){
                cout<<"previous game is not saved:(\n you can play a new game! ";
                cout<<"to start a new game please enter 1\n";
                cin>>y1;
            }


                fread(&line,sizeof(int),1,fptr);
                fread(&pier,sizeof(int),1,fptr);
                fread(&name,sizeof(char),30,fptr);
                fread(&score,sizeof(int),1,fptr);
                fread(a,sizeof(int),400,fptr);

                fclose(fptr);

     }

//**************************************************************************************


     system("cls");



      if(x1==1 || y1==1 || z1==1){
       cout<<"name:";
       cin>>name;
       cout<<"ATTENTION: Entered numbers must be less than 20!";
       cout<<"line:";
       cin>>line;
       cout<<"pier:";
       cin>>pier;


       score=0;




       bool check=true;
       while(check){
                 int y=rand()%(pier-0+1)+0;
                 int x=rand()%(line-0+1)+0;

                  for(int i=0;i<line;++i){
                      for(int j=0;j<pier;++j){
                          if(i==x && j==y){
                            if(a[i][j]==0){
                                a[i][j]=2;
                                check=false;
                            }
                          }
                     }
                 }
            }


    }
    //**********************************************

         cout<<"\n\n\n\n";
     for(int i=0;i<line;++i){
            cout<<"\t\t";
        for(int j=0;j<pier;++j){
                if(a[i][j]<10){
                    cout<<"   "<<a[i][j]<<"    ";
                }
                if(a[i][j]>10 &&a[i][j]<100){
                    cout<<"   "<<a[i][j]<<"   ";
                }

                 if(a[i][j]>100 &&a[i][j]<1000){
                    cout<<"   "<<a[i][j]<<"  ";
                }
                 if(a[i][j]>1000 &&a[i][j]<10000){
                    cout<<"  "<<a[i][j]<<"  ";
                }
                 if(a[i][j]>10000 &&a[i][j]<100000){
                    cout<<"  "<<a[i][j]<<" ";
                }
                 if(a[i][j]>100000 &&a[i][j]<1000000){
                    cout<<" "<<a[i][j]<<" ";
                }

        }
        cout<<"\n\n";

    }
    //*****************************************
     cout<<name<<"\n***********\nscore: "<<score;

     cout<<"\n\n";
    cout<<"\t__________________\n";
    cout<<"\tGUIDE:   \n";
    cout<<"\tUP    -->  1   \n";
    cout<<"\tDOWN  -->  2 \n";
    cout<<"\tRIGHT -->  3\n";
    cout<<"\tLEFT  -->  4 \n";
    cout<<"\tREDO  -->  5 \n";
    cout<<"\tEXIT(save) --> 6 \n";
    cout<<"\tEXIT(without save) --> 7 \n";

    cout<<"\t__________________\n";
    //****************************************



    int n,t;
    while(gaming){


        for(i=0;i<line;++i){
            for(j=0;j<pier;++j){
                if(a[i][j]!=0 && a[i+1][j]!=0 && a[i-1][j]!=0 && a[i][j+1]!=0 && a[i][j-1]!=0){
                    if(a[i][j]!=a[i+1][j] && a[i][j]!=a[i-1][j] && a[i][j]!=a[i][j+1] && a[i][j]!=a[i-1][j]){
                        cout<<"GAME OVWER!\n\n";
                        remove("F:\\mab2048.txt");

                        gaming=false;
                    }
                }
            }
        }

         cin>>n;


        switch(n)
        {
            case 1:
                FILE*fp;
                fp=fopen("F:\\redo.txt","w");

                fwrite(&line,sizeof(int),1,fp);
                fwrite(&pier,sizeof(int),1,fp);
                fwrite(&name,sizeof(char),30,fp);
                fwrite(&score,sizeof(int),1,fp);
                fwrite(a,sizeof(int),400,fp);

                fclose(fp);



                 up(a);



                FILE*fptr;
                fptr=fopen("F:\\mab2048.txt","w");

                fwrite(&line,sizeof(int),1,fptr);
                fwrite(&pier,sizeof(int),1,fptr);
                fwrite(&score,sizeof(int),1,fptr);
                fwrite(&name,sizeof(char),30,fptr);
                fwrite(a,sizeof(int),400,fptr);


                fclose(fptr);


                break;

            case 2:

                fp=fopen("F:\\redo.txt","w");

                fwrite(&line,sizeof(int),1,fp);
                fwrite(&pier,sizeof(int),1,fp);
                fwrite(&name,sizeof(char),30,fp);
                fwrite(&score,sizeof(int),1,fp);
                fwrite(a,sizeof(int),400,fp);

                fclose(fp);

                down(a);

                fptr=fopen("F:\\mab2048.txt","w");


                fwrite(&line,sizeof(int),1,fptr);
                fwrite(&pier,sizeof(int),1,fptr);
                fwrite(&name,sizeof(char),30,fptr);
                fwrite(&score,sizeof(int),1,fptr);
                fwrite(a,sizeof(int),400,fptr);

                fclose(fptr);



                break;

            case 3:

                fp=fopen("F:\\redo.txt","w");

                fwrite(&line,sizeof(int),1,fp);
                fwrite(&pier,sizeof(int),1,fp);
                fwrite(&name,sizeof(char),30,fp);
                fwrite(&score,sizeof(int),1,fp);
                fwrite(a,sizeof(int),400,fp);

                fclose(fp);

                 right(a);

                fptr=fopen("F:\\mab2048.txt","w");



                fwrite(&line,sizeof(int),1,fptr);
                fwrite(&pier,sizeof(int),1,fptr);
                fwrite(&name,sizeof(char),30,fptr);
                fwrite(&score,sizeof(int),1,fptr);
                fwrite(a,sizeof(int),400,fptr);

                fclose(fptr);



                break;

            case 4:

                fp=fopen("F:\\redo.txt","w");

                fwrite(&line,sizeof(int),1,fp);
                fwrite(&pier,sizeof(int),1,fp);
                fwrite(&name,sizeof(char),30,fp);
                fwrite(&score,sizeof(int),1,fp);
                fwrite(a,sizeof(int),400,fp);

                fclose(fp);

                left(a);

                fptr=fopen("F:\\mab2048.txt","w");

                fwrite(&line,sizeof(int),1,fptr);
                fwrite(&pier,sizeof(int),1,fptr);
                fwrite(&name,sizeof(char),30,fptr);
                fwrite(&score,sizeof(int),1,fptr);
                fwrite(a,sizeof(int),400,fptr);


                fclose(fptr);


                break;

            case 5:


            fptr=fopen("F:\\redo.txt","r");
            if(fp==NULL){
                cout<<"No action has been taken so far!";
                exit(0);
            }

             else while(!feof(fp)){

                fread(&line,sizeof(int),1,fp);
                fread(&pier,sizeof(int),1,fp);
                fread(&name,sizeof(char),30,fp);
                fread(&score,sizeof(int),1,fp);
                fread(a,sizeof(int),400,fp);
             }

                fclose(fp);

                break;

            case 6:
                gaming=false;

                break;

            case 7:
                remove("F:\\mab2048.txt");
                gaming=false;


            default:

                break;

        }





        //****************************************************




         bool check=true;
       while(check){
                 int y=rand()%(pier-0+1)+0;
                 int x=rand()%(line-0+1)+0;

                  for(int i=0;i<line;++i){
                      for(int j=0;j<pier;++j){
                          if(i==x && j==y){
                            if(a[i][j]==0){
                                a[i][j]=2;
                                check=false;
                            }
                          }
                     }
                 }
            }



       system("cls");

        //****************************************

         cout<<"\n\n\n\n";
     for(int i=0;i<line;++i){
            cout<<"\t\t";
        for(int j=0;j<pier;++j){
                if(a[i][j]<10){
                    cout<<"   "<<a[i][j]<<"    ";
                }
                if(a[i][j]>10 &&a[i][j]<100){
                    cout<<"   "<<a[i][j]<<"   ";
                }

                 if(a[i][j]>100 &&a[i][j]<1000){
                    cout<<"   "<<a[i][j]<<"  ";
                }
                 if(a[i][j]>1000 &&a[i][j]<10000){
                    cout<<"  "<<a[i][j]<<"  ";
                }
                 if(a[i][j]>10000 &&a[i][j]<100000){
                    cout<<"  "<<a[i][j]<<" ";
                }
                 if(a[i][j]>100000 &&a[i][j]<1000000){
                    cout<<" "<<a[i][j]<<" ";
                }

        }
        cout<<"\n\n";

    }


    //*****************************************
    cout<<name<<"\n***********\nscore: "<<score;


      cout<<"\n\n";
    cout<<"\t__________________\n";
    cout<<"\tGUIDE:   \n";
    cout<<"\tUP    -->  1   \n";
    cout<<"\tDOWN  -->  2 \n";
    cout<<"\tRIGHT -->  3\n";
    cout<<"\tLEFT  -->  4 \n";
    cout<<"\tREDO  -->  5 \n";
    cout<<"\tEXIT(save) --> 6 \n";
    cout<<"\tEXIT(without save) --> 7 \n";

    cout<<"\t__________________\n";
    //****************************************
    }
     FILE*f;
     f=fopen("F:\\scoreboard.txt","a");

                fwrite(&line,sizeof(int),1,f);
                fwrite(&pier,sizeof(int),1,f);
                fwrite(&name,sizeof(char),30,f);
                fwrite(&score,sizeof(int),1,f);

                fclose(f);

    cout<<"\n\n\t******GOOD BYE******\n\n";




     return 0;
}

//END OF THE MAIN

void up(int a[20][20])
{
    int t=0,i,j;


      while(t<line){
              for(j=0;j<pier;++j){
                    for(i=line-1;i>0;i--){
                        if(a[i][j]==0){
                            continue;
                        }
                        if(a[i][j]==a[i-1][j]){
                            score+=a[i][j];
                            a[i-1][j]*=2;
                             if(a[i-1][j]==2048){
                                cout<<"**YOU WIN!**";
                             }
                            a[i][j]=0;
                        }

                        else if(a[i][j]!=0 && a[i-1][j]==0){


                            a[i-1][j]=a[i][j];
                            a[i][j]=0;

                        }


                    }

              }t++;
           }

}


void down(int a[20][20])
{
    int t=0,i,j;
     while(t<line){
                for(j=0;j<pier;++j){
                    for(i=0;i<line-1;++i){
                        if(a[i][j]==0){
                            continue;
                        }
                        else if(a[i][j]!=0 && a[i+1][j]==0){
                            a[i+1][j]=a[i][j];
                            a[i][j]=0;
                        }

                        if(a[i][j]==a[i+1][j]){
                            a[i+1][j]*=2;
                             score+=a[i][j];
                              if(a[i+1][j]==2048){
                                cout<<"**YOU WIN!**";
                             }
                            a[i][j]=0;
                        }
                    }
                }
                t++;
            }

}

void right(int a[20][20])
{
    int i,j,t=0;
     while(t<pier){
                for(i=0;i<line;++i){
                    for(j=0;j<pier-1;++j){
                        if(a[i][j]==0){
                            continue;
                        }
                        else if(a[i][j]!=0 && a[i][j+1]==0){
                            a[i][j+1]=a[i][j];
                            a[i][j]=0;
                        }

                        if(a[i][j]==a[i][j+1]){
                            a[i][j+1]*=2;
                            score+=a[i][j];
                             if(a[i][j+1]==2048){
                                cout<<"**YOU WIN!**";
                             }
                            a[i][j]=0;
                        }
                    }
                }
                t++;
            }
}

void left(int a[20][20])
{
    int t=0,i,j;
    while(t<pier){
                for(i=0;i<line;++i){
                    for(j=pier;j>0;--j){
                        if(a[i][j]==0){
                            continue;
                        }
                        else if(a[i][j]!=0 && a[i][j-1]==0){
                            a[i][j-1]=a[i][j];
                            a[i][j]=0;
                        }

                        if(a[i][j]==a[i][j-1]){
                            a[i][j-1]*=2;
                             score+=a[i][j];
                             if(a[i][j-1]==2048){
                                cout<<"**YOU WIN!**";
                             }
                            a[i][j]=0;
                        }
                    }
                }
                t++;
            }

}


