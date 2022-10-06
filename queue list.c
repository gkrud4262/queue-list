#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{ // 기본 NODE 구조체는 연결리스트와 동일함
    struct NODE *next;// 다음 노드의 포인터를 가르키는 변수 
    int data;// 데이터 변수 저장

} Node;

 
 typedef struct QUEUE{ // 
    Node *front; // 큐에 처음 삽입된 데이터를 가르키는 front 구조체 , node 는 항상 포인터 변수로 동적 할당을 이용하여 변수 만듬
    Node *rear; // 큐에 마지막으로 삽입된 데이터를 가르치는 rear 구조체 
    int size; // 사이즈 변수 저장 
} Queue;
Queue *InitQueue(void){ // QUEUE 구조체 포인터를 초기화
    Queue *queue = (Queue *)malloc(sizeof(Queue)); // 포인트 변수로 동적할당을 이용해 변수를 만들 수 있게 함 
    queue->front = queue->rear = NULL; // front와 rear 모두 NULL로 초기화 
    queue->size = 0; 
    return queue;

}
void ResetQueue(Queue *queue){ // 큐의 저장된 모든 노드를 리셋하고 큐를 초기화 시킴
    Node *tmp; // tmp 포인터 변수
    Node *cur; // cur 포인터 변수 
    cur = queue->front; // cur은 큐에 저장된 연결리스트 노드 중 제일 처음 저장된 노드와 동일함.

    while(cur != NULL){
    tmp = cur->next; // tmp에 현재 cur에 저장된 노드의 다음 노드를 저장
        free(cur);       // 현재 cur에 저장된 노드에 동적할당된 메모리를 해제
        cur = tmp;       // cur은 다음 노드와 동일함

    }
    queue->front = queue->rear = cur;
    queue->size = 0;
}

 void enqueue(Queue *queue, int data){ // 큐에 데이터 추가 
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = data; // 임시 구조체 포인터 tmp에 데이터를 저장
    tmp->next = NULL; // tmp의 next는 NULL 가리킵니다.

    if(queue->size == 0){ // size가 0일 때는 front를 바로 tmp와 동일하게 만듬
        queue->front = tmp; // 이때는 front는 tmp와 동일해지고, rear는 NULL
    }                       
    else{ // size가 0이 아닐 때, 즉, front에 데이터가 저장되어 있을 때 
        queue->rear->next = tmp;    //  front의 반대 방향으로 next 를 보냄
    }                               // rear의 next가 tmp를 가르킨다

    queue->rear = tmp;  // rear 는 temp와 동일, 
    ++queue->size;

}
void dequeue(Queue *queue, int num){
    Node *cur;
    Node *tmp;
     cur = queue->front; //가장 마지막에 들어온 추가된 노드, 큐의 제일 위에 노드
    int size = queue->size;
    printf("");
    while(num--){
        if(cur == NULL){
            printf("Score Queue box is now empty.\n");
            break;

        }
        else{
            printf("Deleted score queue (%d) data = %d.\n", size +1 - (queue->size--), cur->data);
            // 데이터를 반환한 노드의 메모리를 해제하는 부분은 위에 ResetQueue와 동일
            tmp = cur->next;  //Add에서 Queue->rear->next = tmp; 해줬던 부분
            free(cur);
            cur = tmp;
        }
    }
    queue->front = cur;
}
void PrintQueue(Queue *queue){ // 큐의 모든 데이터를 출력
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp = queue->front;
    int size = queue->size-1;
    printf("\n Put score queue starts.");
    while(tmp != NULL){
        printf("Score Queue (%d) data = %d\n", queue->size-(size--), tmp->data);
        tmp = tmp->next;

    }
    printf("Score enqueue is complete.");

}
int main(int argc, const char * argv[]) {
    Queue *queue = InitQueue();
    enqueue(queue, 60);
    enqueue(queue, 74);
    enqueue(queue, 85);
    PrintQueue(queue);
    enqueue(queue, 87);
    enqueue(queue, 90);
    enqueue(queue, 95);
    PrintQueue(queue);
    dequeue(queue, 1);
    dequeue(queue, 2);
    dequeue(queue, 6);
    return 0;
}