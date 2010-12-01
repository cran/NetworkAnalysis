% File NetworkAnalysis/man/vec2sym.Rd
\name{vec2sym}
\alias{vec2sym}
\title{Transform a vector into a corresponding symmetric matrix.}
\description{
       Takes a vector as argument and returns a symmetric matrix whose
       upper triangle is the original vector.}
\usage{
   vec2sym(vec,Nv=NULL)
}
\arguments{
   \item{vec}{A vector.}
   \item{Nv}{Deprecated. For consistency with previous codes only.}
}
\details{
    The function returns a symmetric matrix whose number of rows
    (alternatively columns) is \eqn{1/2 + ((1+8*N)^(1/2))/2},
    where \eqn{N} is the length of the original vector. 

    The resulting symmetric matrix has
    null diagonal entries. We here assume that we are dealing
    with symmetric matrices representing simple graphs, and therefore no
    tadpoles (edge connecting a vertex to itself) are allowed.
}
\value{
    A symmetric matrix with dimensions as aforementioned.
}
\author{
   Cedric E Ginestet <c.ginestet05@gmail.com>
}
\references{
  Ginestet, C.E. and Simmons, A. (In Press). Statistical Parametric Network Analysis of Functional
  Connectivity Dynamics during a Working Memory Task. Neuroimage.
}
\seealso{
   \code{\link{sym2vec}}
}
\examples{

## Upper triangle of correlation matrix of 4 random variables:
ranVar <- cbind(rnorm(100),rnorm(100),rnorm(100),rnorm(100))
R      <- cor(ranVar)
vecR   <- vec2sym(R)

### Combined use of vec2sym() and vec2sym():
ranVar <- cbind(rnorm(100),rnorm(100),rnorm(100),rnorm(100))
R      <- cor(ranVar)
R      <- sym2vec(vec2sym(R))

}
\keyword{symmetric matrix}
