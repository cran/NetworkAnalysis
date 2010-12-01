\name{naCost}
\alias{naCost}
\title{Compute the cost of an unweighted graph.}
\description{Take an unweighted graph as an argument, and returns its cost.}
\usage{
naCost(G)
}
\arguments{
  \item{G}{An unweighted graph.}
}
\details{The cost of a graph is the ratio of the number of its
  connections with the maximal number of possible connections for a
  graph with that number of vertices. 
}
\value{
  \item{Numeric}{The cost: A real number comprised between 0 and 1.}
}
\author{
  Author and maintainer: Cedric E. Ginestet <c.ginestet05@gmail.com>
}
\references{
  Ginestet, C.E. and Simmons, A. (In Press). Statistical Parametric Network Analysis of Functional
  Connectivity Dynamics during a Working Memory Task. Neuroimage.  
}
\examples{

# Construct a random graph.
A <- adjacency.random(10,15)
G <- graph.adjacency(A, mode="undirected",weighted=NULL,diag=FALSE)

# Cost.
print(naCost(G))

}
\keyword{naDensity}
\keyword{cost.int.metric}
