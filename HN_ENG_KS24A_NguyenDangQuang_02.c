#include<stdio.h>
#include<math.h>
int main(){
	
	int n;
	int choice;
	int number[100];
	int chan=0;
	int le=0;
	int max1;
	int max2;
	int index;
	int value;
	int item;
	int check;
	int prime;
	do{
		printf("*******MENU*******\n");
		printf("1.Nhap so phan tu va gia tri cho mang\n");
		printf("2.In ra gia tri cac phan tu trong mang\n");
		printf("3.Dem so luong cac phan tu chan le trong mang\n");
		printf("4.Tim gia tri lon thu hai trong mang\n");
		printf("5.Them mot phan tu vao dau cua mang\n");
		printf("6.Xoa phan tu tai vi tri cu the\n");
		printf("7.Sap xep mang theo thu tu giam dan(Insertion sort)\n");
		printf("8.Cho nguoi dung nhap vao mot phan tu va kiem tra xem phan tu co trong mang hay khong(Binary search)\n");
		printf("9.In ra toan bo so nguyen to da duoc binh phuong\n");
		printf("10.Sap xep mang theo thu tu giam dan(Bubble sort)\n");
		printf("11.Thoat\n");
		printf("moi ban chon (1-11) : ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("moi ban nhap vao so phan tu : ");
				scanf("%d", &n);
				for(int i=0;i<n;i++){
					printf("moi ban nhap phan tu thu %d : \n", i+1);
					scanf("%d", &number[i]);
				}
				break;
			case 2:
				for(int i=0;i<n;i++){
					printf("number[%d]=%d\n", i ,number[i]);
				}
				break;
			case 3:
				for(int i=0;i<n;i++){
					if(number[i]%2==0){
						chan++;
					}else{
						le++;
					}
				}
				printf("so luong so chan trong mang la %d\n ", chan);
				printf("so luong so le trong mang la %d\n ", le);
				break;
			case 4:
				max1=number[0];
				for(int i=0;i<n;i++){
					if(max1<number[i]){
						max2=max1;
						max1=number[i];
					}
				}
				printf("so lon thu hai trong mang la %d ", max2);
				break;
			case 5:
				//them vao vi tri dau tien
				index=0;
				printf("moi ban nhap so muon them : ");
				scanf("%d", &value);
				for(int i=n;i>index;i--){
					number[i]=number[i-1];
				}
				number[index]=value;
				printf("mang sau khi them phan tu la : ");
				for(int i=0;i<n+1;i++){
					printf("%d\t", number[i]);
				}
				break;
			case 6:
				printf("moi ban nhap vi tri muon xoa : ");
				scanf("%d", &index);
				for(int i=index;i<n;i++){
					number[i]=number[i+1];
				}
				printf("mang sau khi xoa la : ");
				for(int i=0;i<n;i++){
		 			printf("%d \t", number[i]);
		 		}
				break;
			case 7:
				for (int i=1;i<n; i++) {
                    int key=number[i];
                    int j=i-1;
                    while(j>=0 &&number[j]<key){
                        number[j+1]=number[j];
                        j--;
                    }
                    number[j+1]=key;
                }
                printf("Mang sau khi sap xep theo thu tu giam dan:\n");
                for(int i=0;i<n;i++) {
                    printf("%d\t",number[i]);
                }
				break;
			case 8:
			    printf("moi nhap gia tri can tim kiem ");
				scanf("%d", &item);
				int start=0;
				int end=n-1;
				int mid;
	
				while(start<=end){
					mid=(start+end)/2;
				if(number[mid]>item){
					end=mid-1;
				}else if(number[mid]<item){
					start=mid+1;
				}else{
					printf("phan tu %d co vi tri index la %d", item, mid);
					return 0;
			
				}
				}
				for(int i=0;i<n;i++){
					if(item!=number[i]){
				printf("phan tu %d khong ton tai trong mang ",item);
				    break;
                }
            }
				break;
			case 9:
				check=0;
             	for(int i=0;i<n;i++)
            	{
                prime=1;
                if(number[i]<2)
                {
                    prime=0;
                }
                else{
                for(int j=2;j<=sqrt(number[i]);j++){
                        if(number[i]%j==0) {
                            prime = 0;
                            break;
                        }   
                    }
                }
                if (prime==1){
                    printf(" so nguyen to da duoc binh phuong la number[%d] = %d\n",i,number[i]*number[i]);
                    check++;
                }
           		 }
            	if (check==0){
                printf("Mang khong co so nguyen to \n");
            	}
				break;
			case 10:
				for (int i=0;i<n;i++) {
                    for (int j=i+1;j<n;j++) {
                        if (number[i]<number[j]) {
                        int temp=number[i];
                            number[i]=number[j];
                            number[j]=temp;
                   }
                }
                }
                printf("mang sau khi sap xep la :");
                for(int i=0;i<n;i++){
                	printf("%d\t", number[i]);
				}
				break;
			case 11:
				printf("Thoat chuong trinh.\n");
                return 0;										
			default:
				printf("lua chon khong hop le.Vui long chon lai\n");
		}	
		
	}while(choice!=11);
	
	return 0;
}
