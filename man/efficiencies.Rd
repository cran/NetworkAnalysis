\name{efficiencies}
\alias{ge}
\alias{le}
\title{The global efficiency of an unweighted simple graph.}
\description{Compute the global efficiency of a graph, as defined by
  Latora and Marchiori (2001).}
\usage{
  ge(obj,D=FALSE)
  le(G)
}
\arguments{
  \item{obj}{Can be an igraph unweighted simple graph, an ajacency
      matrix or a matrix of shortest paths. By default, this function
      accepts both graphs and ajacency matrices.}
  \item{D}{Logical: If obj is a matrix of shortest paths, then this flag
     should be turned to TRUE.}
  \item{G}{A simple graph, i.e. unweighted, acyclic and without tadpoles.}
}
\details{
  The global and local efficiencies of a simple graph are standardized
  equivalent of the characteristic path length and clustering
  coefficient, respectively. Their values are comprised between 0 and
  1.

  These functions are only valid for unweighted graphs. For weighted
  graphs, one can use the integrated versions of these metrics, using
  either the cost.int.metric or the cutoff.int.metric functions. 
}
\value{
  \item{Numeric}{A real number between 0 and 1.}
}
\author{
   Cedric E. Ginestet <c.ginestet05@gmail.com>
}
\references{  
  Latora, V. & Marchiori, M. Efficient Behavior of Small-World Networks (2001).
  Phys. Rev. Lett., American Physical Society, 87, 198701-198705.

  Latora, V. & Marchiori, M. Economic small-world behavior in weighted
  networks (2003). The European Physical Journal B - Condensed Matter and
  Complex Systems, 32, 249-263.  
}
\examples{

# Construct a random graph.
A <- adjacency.random(10,15)
G <- graph.adjacency(A, mode="undirected",weighted=NULL,diag=FALSE)

# Global and local efficiencies.
ge(G)
le(G)

}
\keyword{cost.int.metric}
\keyword{cutoff.int.metric}
