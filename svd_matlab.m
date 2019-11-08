A1 = [1,2,3;4,5,6];
A2 = [1,2;3,4;5,6];
[u1,s1,v1]=svd(A1);
[u2,s2,v2]=svd(A2);
A1_ = u1*s1*transpose(v1);
A2_ = u2*s2*transpose(v2);
A1_
A2_