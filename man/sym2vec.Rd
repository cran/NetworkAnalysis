% File NetworkAnalysis/man/sym2vec.Rd
\name{sym2vec}
\alias{sym2vec}
\title{Transform a symmetric matrix into a vector.}
\description{
       Takes a symmetric matrix as argument and returns the upper
       off-diagonal entries as a vector. This is a very useful function,
       as in practice, all analyses of symmetric matrix can be
       simplified by only considering the upper triangle.}
\usage{
   sym2vec(A)
}
\arguments{
   \item{A}{a symmetric matrix.}
}
\details{
    The function returns an error message if the argument is not a
    symmetric matrix.

    The symmetric matrix is read columnwise, starting from entry [1,2],
    then [1,3] to [1,4], and continuing until the last column.

    Diagonal entries are ignored. We here assume that we are dealing
    with symmetric matrices representing simple graphs, and therefore no
    tadpoles (edge connecting a vertex to itself) are allowed. 
}
\value{
  The function returns a vector of size:
  \deqn{{n\choose 2}=\frac{n(n-1)}{2}}{n*(n-1)/2},
  where the matrix is of order \eqn{n\times n}.
}
\author{
   Cedric E Ginestet <c.ginestet05@gmail.com>
}
\references{
  Ginestet, C.E. (In Press). Statistical Parametric Network Analysis of Functional
  Connectivity Dynamics during a Working Memory Task. Neuroimage.
}
\seealso{
   \code{\link{vec2sym}}
}
\examples{

## Upper triangle of correlation matrix of 4 random variables.
ranVar <- cbind(rnorm(100),rnorm(100),rnorm(100),rnorm(100))
R      <- cor(ranVar)
vecR   <- sym2vec(R)

### Combined use of vec2sym() and vec2sym():
ranVar <- cbind(rnorm(100),rnorm(100),rnorm(100),rnorm(100))
R      <- cor(ranVar)
R      <- sym2vec(vec2sym(R))

}
\keyword{symmetric matrix}
