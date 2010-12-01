\name{naDensity}
\alias{naDensity}
\title{Compute the weighted cost (density) of a weighted graph.}
\description{Take a similarity matrix as an argument, and returns its
  weighted cost or density.}
\usage{
naDensity(R)
}
\arguments{
  \item{R}{A similarlity symmetric matrix.}
}
\details{For a weighted graph, the density or weighted cost is simply
  defined as the mean off-diagonal element.      
}
\value{
  \item{Numeric}{The cost: A real number not necessiarly comprised
    between 0 and 1. This depends on whether or not the original
    similarity matrix was standardized or not.}
}
\author{
  Cedric E. Ginestet <c.ginestet05@gmail.com>
}
\references{
  Ginestet, C.E. and Simmons, A. (In Press). Statistical Parametric Network Analysis of Functional
  Connectivity Dynamics during a Working Memory Task. Neuroimage.  
}
\examples{

# Construct a random graph.
R <- cor(cbind(rnorm(100),rnorm(100),rnorm(100),rnorm(100),rnorm(100),rnorm(100)))
print(R);

# Density.
naDensity(R)

}
\keyword{naCost}
\keyword{cost.int.metric}
