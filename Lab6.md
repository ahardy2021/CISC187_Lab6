1.
```
Stack(6):
| | | | | | |
 h

Push(S,4):
|4| | | | | |
   h

Push(S,1):
|4|1| | | | |
     h

Push(S,3):
|4|1|3| | | |
       h

Pop(S):
|4|1|3| | | |
     h
--> 3

Push(S,8):
|4|1|8| | | |
       h

Pop(S):
|4|1|8| | | |
     h
--> 8
```
2. 
```
h = head (first out)
t = tail (first in)
Queue(6)
| | | | | | |
 h
 t

Enqueue(Q,4):
|4| | | | | |
 h t

Enqueue(Q,1):
|4|1| | | | |
 h   t

Enqueue(Q,3):
|4|1|3| | | |
 h     t

Dequeue(Q):
|4|1|3| | | |
   h   t
--> 4

Enqueue(Q,8):
|4|1|3|8| | |
   h     t

Dequeue(Q):
|4|1|3|8| | |
     h   t
--> 1
```
3. See attached `Lab6.cpp`. I threw in Stack for some practice, disregard.
4. See attached `Lab6.cpp`.
