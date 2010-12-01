sym2vec <-
function(A){  
   # Take symmetric matrix and return sparse version. 
   n1 <- length(A[1,]); n2 <- length(A[,1]); 
   if(n1 != n2) stop("Not square matrix to sym().")
   out <- vector()
   for(i in 2:n1){
       for(j in 1:(i-1)){
           if (i==2) out[1] <- A[j,i] else out[sum(1:(i-2))+j] <- A[j,i]
        }# j in (i-1)
   }# i in n1
return(out)  
}

