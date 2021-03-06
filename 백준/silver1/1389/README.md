# 케빈 베이컨의 6단계 법칙

## 문제 링크
https://www.acmicpc.net/problem/1389

## 풀이 방법
BFS

## 간단한 풀이 설명
1번 사람부터 N번 사람까지 BFS 탐색을 시킨다.<br>
987654321로 초기화된 최소 거리 2차 배열에 최소값을 갱신시켜 나간다.<br>
최소값이 모두 구해지고 나면 총합 거리가 가장 작은 사람의 번호를 구한다.<br>

## 실수했던 부분
41번 라인에서 if (min_length[j][i] > Queue[front + 1].distan)와 같이 썼었는데,<br>
1번과 3번의 최소거리가 구해진 후, 나중에 3번에서 1번을 통해 4번으로 가는 최소 거리를 구해야할 때<br>
등호(=)가 없기 때문에, 큐에 BFS 탐색이 들어가지 않아 3번에서 4번으로 가는 최소 거리를 못찾는 상황이 생긴다.<br>
