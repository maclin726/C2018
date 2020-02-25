#include <stdio.h>
#include "50187.h"
 
int main() {
  int n, m;
  MST mst;
  scanf("%d%d", &n, &m);
  init(&mst, n);
  for(int i = 0, j, k, l, s; i < m; i++) {
    scanf("%d", &j);
    switch(j) {
      case 0:
        scanf("%d%d%d", &k, &l, &s);
        addRoad(&mst, k, l, s);
        printf("Add road.\n");
        break;
      case 1:
        scanf("%d%d", &k, &l);
        s = removeRoad(&mst, k, l);
        printf("Remove road of length %d.\n", s);
        break;
      case 2:
        s = connected(&mst);
        printf("MST is %sconnected.\n", s ? "" : "not ");
        break;
      case 3:
        scanf("%d%d", &k, &l);
        s = hasPath(&mst, k, l);
        printf("There is %sa path.\n", s ? "" : "not ");
        break;
    }
  }
        return 0;
}