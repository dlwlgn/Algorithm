# 무인도 탈출

## 문제 링크
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWL6HGz6Ai4DFAUY

## 풀이 방법
DFS

## 간단한 풀이 설명
N개의 직육면체 중 어느 직육면체, 그리고 이 직육면체를 어떤 면으로 세울 것인지(직육면체는 3면이 서로 다를 수 있다) DFS 탐색으로 결정한다. <br>
아래 깔리는 직육면체보다 가로 세로가 둘다 작거나 같아야 하므로 if문으로 체크해준다. (여기서 긴 면을 가로로 보고, 짧은 면을 세로로 본다) <br>
높이를 total_height에 갱신시켜주다가 모든 직육면체를 다 쌓았을 때 max_height 변수를 갱신시켜주며 제일 높은 방법을 찾는다. <br>

## 아쉬운 부분
이 문제 또한 백트래킹을 해줄 방법을 찾지 못해서 별도로 백트래킹이 들어가있지 않다. <br>
결과적으로 샘플 테스트케이스에서도 5개 중 4개만 나오고 마지막 테스트케이스는 나오지 않는다. <br>