#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char string [50];
typedef struct passenger* passenger_ptr; // define new datatype struct passenger*
typedef struct passenger{
    int ID ;
    int date ;
    string time  ;
    string from;
    string to;
    passenger_ptr next ;
};
typedef passenger_ptr pos;
typedef passenger_ptr passengersList ;
FILE *file;
FILE *file2;

//trim function
void rtrim(char a[50]) {
    char rtrim[50]="\0";
    int i=strlen(a)-1;
    while (i>=0) {
        if (a[i]==' '|| a[i]=='\t') {rtrim[i]='\0'; i--;}
        if (a[i]!=' ' && a[i]!='\t') {break;}
    }
    while (i>=0) { rtrim[i]=a[i]; i--; }
}
void ltrim(char b[50]) {
    char ltrim[50]="\0";
    int i=0,j=0;
    while (b[i]!='\0') {
        if (b[i]!=' ' && b[i]!='\t') {break;}
        i++;
    }
    while (b[i]!='\0') {
        ltrim[j]=b[i];
        i++;
        j++; }

}
void trim(char c[50]) {

    char rtrim[50]="\0";

    int i=strlen(c)-1;

    while (i>=0) {

        if (c[i]==' '|| c[i]=='\t') {rtrim[i]='\0';}
        if (c[i]!=' ' && c[i]!='\t') {break;}
        i--; }

    while (i>=0) {
        rtrim[i]=c[i];
        i--; }
    char ltrim[50]="\0";
    int j=0,k=0;
    while (rtrim[j]!='\0')
    {
        if (rtrim[j]!=' ' && rtrim[j]!='\t') {break;}
        j++;
    }
    while (rtrim[j]!='\0') {
        ltrim[k]=rtrim[j];
        j++;
        k++; }
    char trim[50];
    strcpy (trim, ltrim);

}

void passengerInsert(int id ,int date,string time ,string from,string to,passengersList pass  , passenger_ptr  pos){// Adding node to the list after position Pos
    struct passenger*temp1; // pointer to the node
    temp1 = (struct  passenger*) malloc(sizeof(struct  passenger));
    //cutting spaces for strings
    rtrim(time);
    ltrim(time);
    trim(time);
    rtrim(from);
    ltrim(from);
    trim(from);
    rtrim(to);
    ltrim(to);
    trim(to);
    if(temp1 != NULL ) {
        temp1->ID = id;
        temp1->date = date;
        strcpy(temp1->time,time);
        strcpy(temp1->from,from);
        strcpy(temp1->to,to);
        temp1->next = pos->next;
        pos->next = temp1;
    } else{
        printf("OooooPss!!!!ERROR");
    }
}

typedef struct busses* bus_ptr; // define new datatype struct busses*
typedef struct busses{
    int num ;
    int busDate ;
    string departure_time ;
    string busFrom;
    string busTo;
    int price;
    int capacity;
    int count;
    passenger_ptr point;
    struct busses * next ;
};busses , *bussesPtr ;
typedef bus_ptr bussesList ;
typedef bus_ptr m;

//function to insert a node to busses linked list
void busInsert(int num ,int D,string departure_time ,string Bfrom,string Bto, int price,int capacity,bussesList b , bus_ptr p){// Adding node to the list after position P
    struct busses*temp3; // pointer to the node
    temp3 = (struct  busses*) malloc(sizeof(struct  busses));
    //cutting spaces for the strings
    rtrim(departure_time);
    ltrim(departure_time);
    trim(departure_time);
    rtrim(Bfrom);
    ltrim(Bfrom);
    trim(Bfrom);
    rtrim(Bto);
    ltrim(Bto);
    trim(Bto);
    temp3->point=(passenger_ptr)malloc(sizeof(struct passenger));
    temp3->point->next=NULL;
    if(temp3 != NULL ) {
        temp3->num = num;
        temp3->busDate = D;
        strcpy(temp3->departure_time,departure_time);
        strcpy(temp3->busFrom,Bfrom);
        strcpy(temp3->busTo,Bto);
        temp3->price = price;
        temp3->capacity = capacity;
        temp3->count=0;
        temp3->next = p->next;
        p->next = temp3;
    } else{
        printf("OooooPss!!!!ERROR!!!!");
    }
}


typedef struct waiting* waiting_ptr; // define new datatype struct waiting*
typedef struct waiting{
    int wID ;
    int wdate ;
    string wtime  ;
    string wfrom;
    string wto;
    struct waiting * next ;
};waiting ,  *waitingPtr ;
typedef waiting_ptr waitingList ;

//function to insert node in waitig list
void waitingInsert(waitingList w,int id ,int date,string time ,string from,string to,waiting_ptr position){
    struct waiting*temp4; // pointer to the node
    temp4 = (struct  waiting*) malloc(sizeof(struct  waiting));
    if(temp4 != NULL ) {
        temp4->wID = id;
        temp4->wdate = date;
        strcpy(temp4->wtime,time);
        strcpy(temp4->wfrom,from);
        strcpy(temp4->wto,to);
        temp4->next = position->next;
        position->next = temp4;
    } else{
        printf("OooooPss!!!!ERROR");
    }
}


int isWaitingExist(waitingList b){//function to check if the list exist
    return b != NULL;
}
int isWaitingEmpty( waitingList b) {//function to check if the list empty
    if (isWaitingExist(b)) {
        return b->next == NULL;
    } else {
        printf("your List is not Exist !");
        return 0;
    }
    //only head in it
}
int  isWaitingLast(waitingList b , waiting_ptr Po){//function to check if po is the last node
    return  Po->next == NULL;
}

void  printUnMatchedList( waitingList l ) {//function to print waiting list
       waiting_ptr p;
        p = l;
        if (isWaitingEmpty(l)) {
            printf("Empty list !");
        } else {
            do {
                p = p->next;
                printf("\n%d ", p->wID);
                printf("%-1d ", p->wdate);
                printf("%s\t" ,p->wfrom);
                printf("%d \t", p->wto);
                printf("%d \t", p->wtime);
            } while (!isWaitingLast(l, p));
            printf("\n");
        }

    }


int isExist(passengersList b){//function to check if passenger list is exist
    return b != NULL;
}
int isEmpty( passengersList b) {//function to check if passenger list is empty
    if (isExist(b)) {
        return b->next == NULL;
    } else {
        printf("your List is not Exist !");
        return 0;
    }
    //only head in it
}
int  isLast(passengersList b , passenger_ptr Po){//function to check if this node is the last node in the list
    return  Po->next == NULL;
}

void passPrint ( passengersList b ) {//function to print passengers linked list
    struct passenger*po;
    po = b;
    if (isEmpty(b)) {
        printf("Empty list !");
    } else {
        do {
            if (po!=NULL) {
                po = po->next;
                printf("%d\n", po->ID);
                printf("%d\n", po->date);
                printf("%s\n", po->time);
                printf("%s\n", po->from);
                printf("%s\n", po->to);
                printf("\n");
            }
        } while (!isLast(b, po));
        printf("\n");
    }
}

//function to print busses data
void busInfo(bussesList bus){
    bus_ptr ptr3;
    ptr3 = bus;
    ptr3 = ptr3->next;
    while (ptr3!=NULL) {
        printf("num: %d\n",ptr3->num);
        printf("date: %d\n", ptr3->busDate);
        printf("time: %s\n",ptr3->departure_time);
        printf( "from: %s\n",ptr3->busFrom);
        printf( "to: %s\n",ptr3->busTo);
        printf("prince: %d\n", ptr3->price);
        printf("capacity: %d\n", ptr3->capacity);
        printf("passengers:\n");
        passPrint(ptr3->point);
        ptr3=ptr3->next;
        printf("\n");
    }
}


//function assign passenger to the busses linked list or to waiting linked list
void assignPassenger(passengersList pass,bussesList b,waitingList w ) {
    passenger_ptr psl = pass->next;
   waiting_ptr wp =w;
    bussesList bs = b->next;
    if (bs!=NULL);
    while (psl != NULL) {
        bs = b->next;
        while (bs!=NULL){
            if (psl->date == bs->busDate && strcmp(psl->time, bs->departure_time) == 0 &&
                strcmp(psl->from, bs->busFrom) == 0 && strcmp(psl->to, bs->busTo) == 0) {
                if (bs->count <= bs->capacity) {
                    passenger_ptr o = bs->point;
                    passengerInsert(psl->ID, psl->date, psl->time, psl->from, psl->to, bs->point, o);
                    bs->count++;
                } else {
                    waitingInsert(w, psl->ID, psl->date, psl->time, psl->from, psl->to, wp);
                }
            }
                bs = bs->next;
        }
        psl = psl->next;
    }
    busInfo(b);
}



//function to print specific bus information with its passenger information
void printBusInfo(bussesList bus,int num) {
    bus_ptr ptr3;
    ptr3 = bus->next;
 if (ptr3->num==num){
     printf("\n Num: %d",ptr3->num);
     printf("date: %-1d",ptr3->busDate);
     printf("time: %s\t",ptr3->departure_time);
     printf("From: %s\t",ptr3->busFrom);
     printf("To: %s\t",ptr3->busTo);
     printf("Price: %-2d",ptr3->price);
     printf("capacity:%-4d",ptr3->capacity);
     passPrint(ptr3->point);
 }else
     ptr3=ptr3->next;
}

//function to add new passenger
void addPassenger(bussesList bus,waitingList w){
    passenger_ptr ptr6=(passenger_ptr) malloc(sizeof (struct  passenger));
    passengersList p = (passenger_ptr) malloc(sizeof(struct passenger));//creation new linked list
    p->next=NULL;
    int passengerID,passengerDate;
    string passengerTime,passengerFrom,passengerTo;
    //read data and assing it to node ptr6
    printf("\nEnter passenger's ID ");
    scanf("\n%d",&passengerID);
    ptr6->ID=passengerID;
    printf("\nEnter the date ");
    scanf("\n%d",&passengerDate);
    ptr6->date=passengerDate;
    printf("\nEnter the time\n ");
    gets(passengerTime);
    gets(passengerTime);
    strcpy(ptr6->time,passengerTime);
    printf("\n from where?");
    gets(passengerFrom);
    gets(passengerFrom);
    strcpy(ptr6->from,passengerFrom);
    printf("\n To where? ");
    gets(passengerTo);
    gets(passengerTo);
    strcpy(ptr6->to,passengerTo);
    //calling assignPassenger function to assing the new passenger
    ptr6->next=p->next;
    p->next=ptr6;
    printf("%d",ptr6->ID);
    assignPassenger(p,bus,w);
}

//function to find pervious passenger that assignes in busses list
struct passenger* PassPrevious( bussesList bus,int pId){
    passenger_ptr ptr8;
    bus_ptr i=bus;

    while(ptr8->next != NULL && i->point->next->ID != pId)
        i=i->point->next;
        ptr8=i;
    return ptr8;
}

//function to find pervious passenger that assignes in waiting list
struct passenger* Pass_waitingPrevious( waitingList w,int pId){
    passenger_ptr ptr8;
    waiting_ptr i=w;

    while(ptr8->next != NULL && i->next->wID != pId)
        i=i->next;
        ptr8=i;
    return ptr8;
}

struct passenger *find(int x, passengersList l){// Search on data in the nodes
    passenger_ptr p;
    p = l->next;
    while (p!= NULL && p->ID != x){
        p = p->next;
    }
    return  p;
}

//function to delete passenger from busses list or from waiting
void deletePassenger(int dID,bussesList bus,waitingList w) {
    bus_ptr temp = bus->next;
    waiting_ptr tempW = w->next;
    waiting_ptr t, k;
    passenger_ptr pre, l;
    while (temp != NULL) {
        if (temp->point->ID == dID) {
            pre = PassPrevious(temp->point, dID);
            if (isLast(temp->point, pre)){
            l->next = temp->point->next;
            pre->next = l->next;
            free(pre);
        } else {
            while (tempW != NULL) {
                if (tempW->wID == dID) {
                    t = Pass_waitingPrevious(w, dID);
                    if (isWaitingLast(w, pre));
                    k->next = tempW->next;
                    pre->next = k->next;
                    free(pre);
                }
            }
                tempW = tempW->next;
            }
            temp = temp->next;
        }
        printf("NOT FOUND!!!!");
    }
}

//function to find previous node in busses list
struct busses* findPrevious( bussesList bus,int num){
    bus_ptr ptr7;
    ptr7 = bus;
    while(ptr7->next != NULL && ptr7->next->num != num)
        ptr7 = ptr7->next;
    return ptr7;
}

//function to delete list
void  delete_all_List( passengersList l){// all elements
    passenger_ptr p,temp;
    p = l->next;
    l->next = NULL;
    while ( p != NULL){
        temp = p->next;
        free(p);
        p = temp;
    }
}

//function to find last in busses linked list
int  isBusLast( bussesList l , bus_ptr P){
    return  P->next == NULL;

}

    //function to delete bus
    void deleteBus(bussesList bus, int busNum,waitingList w){
    bus_ptr temp7=bus->next;
    bus_ptr ptrB,ptr9;
    waiting_ptr r;
    while(temp7!=NULL){
        if (temp7->num==busNum){
            ptrB= findPrevious(bus,busNum);
            if (!isBusLast(bus,busNum)){
              ptr9=ptrB->next;
              if (temp7->point!=NULL) {
                  while (temp7->point->next != NULL) {
                      r->wID = temp7->point->ID;
                      r->wdate = temp7->point->date;
                      strcpy(r->wtime, temp7->point->time);
                      strcpy(r->wfrom, temp7->point->from);
                      strcpy(r->wto, temp7->point->to);
                      waitingInsert(w, r->wID, r->wdate, r->wtime, r->wfrom, r->wto, w);
                  }
              }
                free(temp7);
            }
        }else
            printf("OooooooPSSS!!! BUS NOT FOUND");
    }
}

void readPassengers(passengersList pass){
    pos ptr1 =pass;
    int id,d;
    string t,f,To ={ };
    string temp;//string to read the file line by line
    //open files
    file = fopen("passengers.txt", "r");
    //to check if passenger file is exist
    if(file == NULL) {
        printf("file is not exist");
        exit(1);
    }
    // split from the file ,then insert data inside the linked list
    while(fgets(temp,100,file)!=NULL){
        id=atoi(strtok(temp,"#"));
        d=atoi(strtok(NULL,"#"));
        strcpy(t,strtok(NULL,"#"));
        strcpy(f,strtok(NULL,"#"));
        strcpy(To,strtok(NULL,"#"));
        passengerInsert(id,d,t,f,To,pass,ptr1);
        //ptr1=ptr1->next;
    }

    fclose(file);
}
void readBusses(bussesList bus){
    m ptr2;
    ptr2=bus;
    int no,busD,price,capacity;
    string dTime,busf,busTo;
    string temp2;//string to read the file line by line
    //open files
    file2 = fopen("busses.txt", "r");
    //to check if busses file is exist
    if(file2 == NULL) {
        printf("file is not exist");
        exit(2);
    }
    // split from the file ,then insert data inside the linked list
    while(fgets(temp2,100,file2)){
        no=atoi(strtok(temp2,"#"));
        busD=atoi(strtok(NULL,"#"));
        strcpy(dTime,strtok(NULL,"#"));
        strcpy(busf,strtok(NULL,"#"));
        strcpy(busTo,strtok(NULL,"#"));
        price=atoi(strtok(NULL,"#"));
        capacity=atoi(strtok(NULL,"#"));
        busInsert( no , busD, dTime , busf, busTo,  price, capacity, bus ,  ptr2);

    }
    fclose(file2);
}


    int main() {
        waiting_ptr w = (waiting_ptr) malloc(sizeof(struct waiting));
        w->next = NULL;
        passenger_ptr Pass = (passenger_ptr) malloc(sizeof(struct passenger));
        Pass->next = NULL;
        bus_ptr buss = (bus_ptr) malloc(sizeof(struct busses));
        buss->next = NULL;
       char * menu ="\nChoose one of these Operations.\n"
                     "1. Load the bus information file.\n"
                     "2. Load the bus information file.\n"
                     "3. Assign passengers and print assignment information of all \n"
                     "busses.\n"
                     "4. Print a specific bus information along with its passengers \n"
                     "information.\n"
                     "5. Print unmatched passengers.\n"
                     "6. Add new passenger.\n"
                     "7. Delete passenger.\n"
                     "8. Delete bus number\n"
                     "9. Exit\n" ;

       bool doneReading1=false;
       bool doneReading2=false;
       int y,e,q;
        int choice ;
        printf(menu) ; // Select From Menu
        scanf("%d" , &choice) ;
        while(1){
            switch(choice){
                case 1 :
                    readBusses(buss);
                    doneReading1=true;

                    break ;
                case 2 :
                    if(doneReading1==true) {
                        readPassengers(Pass);
                        doneReading2=true;

                    }else
                        printf("read busses file first\n");
                    break ;
                case 3 :
                    if(doneReading1==true&&doneReading2==true) {
                        assignPassenger(Pass,buss,w);
                    }else printf("Read The Files First\n") ;
                    break ;

                case 4 :
                    if(doneReading1==true&&doneReading2==true) {
                        printf("enter the bus number\n");
                        scanf("%d",&y);
                        printBusInfo(buss,y);
                    }else printf("Read The Files First\n") ;
                    break ;

                case 5 :
                    if(doneReading1==true&&doneReading2==true) {
                        printUnMatchedList(w);
                    }else printf("Read The Files First\n") ;
                    break ;

                case 6 :
                    if(doneReading1==true&&doneReading2==true) {
                        addPassenger(buss,w);
                    }else printf("Read The Files First\n") ;
                    break ;
                case 7 :
                    if(doneReading1==true&&doneReading2==true) {
                        printf("enter id of pssenger you want to delete\n");
                        scanf("%d",&e);
                        deletePassenger(e,buss,w);
                    }else printf("Read The Files First\n") ;
                    break ;

                case 8:
                    if(doneReading1==true&&doneReading2==true) {
                        printf("enter id of bus you want to delete\n");
                        scanf("%d",&q);
                        deleteBus(buss,q,w);
                    }else printf("Read The Files First\n") ;
                    break ;

                case 9:
                    return 0 ;
                default : printf("Wrong Entry , Please Try Again\n") ;
            }

            printf(menu) ; // Select From Menu Again
            scanf("%d" , &choice) ;
        } // End Of While Loop

    }

