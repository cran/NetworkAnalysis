\name{bound.standard}
\alias{bound.standard}
\title{Standardization of bounds when partially integrating topological metrics.}
\description{This is a small function for the standardization of the
  integration bounds when computing the cost-integrated version
  of the topological metrics of a given
  weighted graph.}
\usage{
bound.standard(bounds, Ne)
}
\arguments{
  \item{bounds}{A numeric vector of size 2, describing the lower and
    upper bound of the integral of interest.}
  \item{Ne}{Number of edges.}
}
\value{
    \item{bounds}{Standardized bounds in terms of nubmer of edges.}
}
  \author{
     Cedric E Ginestet <c.ginestet05@gmail.com>
}
\references{
  Ginestet, C.E. and Simmons, A. (In Press). Statistical Parametric Network Analysis of Functional
  Connectivity Dynamics during a Working Memory Task. Neuroimage.
}
\seealso{cost.int.metric, cutoff.int.metric}
\examples{
# Standardize bounds in terms of number of edges. 
bound.standard(c(.1,.6),25) 
}
\keyword{lower bound}
\keyword{upper bound}
\keyword{integration}
