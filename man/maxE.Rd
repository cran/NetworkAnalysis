\name{maxE}
\alias{maxE}
\title{The number of edges of a saturated (complete) graph.}
\description{
    Given a number of vertices, this function returns the maximal number
    of edges that a simple with that number of vertices can
    have. Equivalently, this function returns the size of the saturated
    graph with order Nv.
}
\usage{
maxE(Nv)
}
\arguments{
  \item{Nv}{The number of vertices of the saturated graph of interest.}
}
\details{
  The order (i.e. number of edges) of a saturated graph is
  \eqn{Nv*(Nv-1)/2}. 
}
\value{
  \item{Numeric}{Returns an integer.}
}
\author{
  Author and maintainer: Cedric E. Ginestet <c.ginestet05@gmail.com>
}
\references{
  Ginestet, C.E. and Simmons, A. (In Press). Statistical Parametric Network Analysis of Functional
  Connectivity Dynamics during a Working Memory Task. Neuroimage.  
}
\examples{

### Size of a saturated graph of order 10.
Nv <- 10
print(maxE(Nv))

}
\keyword{cost}
\keyword{den}
