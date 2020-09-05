#include <pthread.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

typedef struct PCB {
  char name[10];
  int arriveTime;
  char state;
  atomic_int runTime;
  atomic_bool can_run;
} PCB;

#define PROC_NUM 10
typedef struct ProcCtrl {
  int proc_num;
  PCB *procs[PROC_NUM];
  int runi;  // 当前运行的进程块索引
} ProcCtrl;

void *proc_run(void *ptr) {
  PCB *p = (PCB *)ptr;
  pthread_t tid = pthread_self();
  printf("进程[%s/%ld]  等待运行\n", p->name, (long)tid);
  while (p->runTime > 0) {
    if (!p->can_run) {
      continue;
    }
    printf("进程[%s/%ld] 正在运行...\n", p->name, (long)tid);
    fflush(stdout);
    usleep(300);
  }
  return NULL;
}

void proc_ctrl_init(ProcCtrl *ctrl) {
  ctrl->proc_num = PROC_NUM;
  for (int i = 0; i < ctrl->proc_num; i++) {
    PCB *p = malloc(sizeof(PCB));
    sprintf(p->name, "P%d", i + 1);
    p->arriveTime = rand() % 20 + 1;
    p->runTime = rand() % 10 + 1;
    p->can_run = false;
    p->state = 'R';
    ctrl->procs[i] = p;
    pthread_t tid;
    int ret = pthread_create(&tid, NULL, proc_run, p);
    if (ret == -1) {
      perror("pthread_create failed");
    }
    ret = pthread_detach(tid);
    if (ret == -1) {
      perror("pthread_detach failed");
    }
  }
}

void swap_pcb(PCB *a, PCB *b) {
  PCB tmp;
  const int pcb_size = sizeof(PCB);
  memcpy(&tmp, b, pcb_size);
  memcpy(b, a, pcb_size);
  memcpy(a, b, pcb_size);
}

void proc_ctrl_show(ProcCtrl *ctrl) {
  const int N = ctrl->proc_num;
  printf("---------------------------------------------\n");
  printf("进程名\t到达时间\t估计运行时间\t状态\n");
  printf("---------------------------------------------\n");
  for (int i = 0; i < N; i++) {
    PCB *p = ctrl->procs[i];
    if (p->state == 'C') {
      continue;
    }
    printf("%6s\t%8d\t%12d\t%c\n", p->name, p->arriveTime, p->runTime,
           p->state);
  }
}

void proc_ctrl_sort_procs(ProcCtrl *ctrl) {
  // 简单的冒泡排序
  const int N = ctrl->proc_num;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N - 1; j++) {
      PCB *cur = ctrl->procs[j];
      PCB *next = ctrl->procs[j + 1];
      if (cur->arriveTime > next->arriveTime) {
        PCB *tmp = next;
        ctrl->procs[j + 1] = cur;
        ctrl->procs[j] = tmp;
      }
    }
  }
}

void proc_ctrl_round(ProcCtrl *ctrl) {
  int i = 0;
  while (true) {
    int runing_proc_cnt = 0;
    for (int i = 0; i < ctrl->proc_num; i++) {
      PCB *p = ctrl->procs[i];
      if (p->state == 'C') {
        continue;
      }
      if (p->runTime < 1) {
        p->state = 'C';
        continue;
      }
      p->can_run = true;
      usleep(200);
      p->runTime -= 1;
      p->can_run = false;
      runing_proc_cnt += 1;
    }
    printf("\n进程当前调度状态表:\n");
    proc_ctrl_show(ctrl);
    if (runing_proc_cnt < 1) {
      break;
    }
  }
  printf("所有进程运行完成!\n");
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  ProcCtrl ctrl;
  proc_ctrl_init(&ctrl);
  proc_ctrl_sort_procs(&ctrl);
  printf("初始进程调度表:\n");
  proc_ctrl_show(&ctrl);
  printf("进程开始运行:\n");
  proc_ctrl_round(&ctrl);

  return 0;
}
