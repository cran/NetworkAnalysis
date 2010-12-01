ge <-
function(obj,D=FALSE){
    D    <- naObj(obj,D=D); Dvec <- sym2vec(D); 
    out  <- mean(1/Dvec); 
return(out)
}

