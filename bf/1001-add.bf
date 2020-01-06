,       # takes user input and stores it in idx1
>       # moves pointer to next index (idx2)
,       # takes user input and stores it in idx2
[
  <     # moves pointer to idx1
  +     # increments idx1
  >     # moves pointer to idx2
  -     # decrements idx2
]     # exits loop when idx2 is empty
<     # moves the pointer back to idx1
------------------------------------------------ ; # subtract 48 (ASCII char code of '0')
.     # prints value in idx1
