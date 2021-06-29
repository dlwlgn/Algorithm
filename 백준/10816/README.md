# 숫자 카드2

## 문제 링크
https://www.acmicpc.net/problem/10816

## 풀이 방법
이진 탐색 Lower Bound & Upper Bound

## 간단한 풀이 설명
입력받은 카드 번호들을 이진 탐색할 수 있게 정렬한다. <br>
Upper Bound와 Lower Bound를 구해서 입력받은 숫자의 카드가 몇개있는지 구한다. <br>

## 실수했던 부분
Upper Bound와 Lower Bound를 구하는 과정에서 무한 루프가 생기게 코드를 작성했었다. <br>
first, mid, last 중 어떤 것을 해야할지, 어떤 것에 +1을 붙이고 어떤 것에 +1을 붙이지 않아야 할지 헷갈려서 실수를 했다. <br>
