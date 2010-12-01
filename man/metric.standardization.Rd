\name{metric.standardization}
\alias{metric.standardization}
\title{Standardization of a similarity real-valued matrix.}
\description{
    Takes a similarity matrix (e.g. a correlation matrix) as an argument
    and returns a standardized matrix with values comprised between 0
    and 1.
}
\usage{
metric.standardization(R, type = "correlation")
}
\arguments{
  \item{R}{A correlation matrix.}
  \item{type}{Character: The type of similarity measure used in the
    matrix. Currently, only "correlation" is accepted as an argument.}
}
\details{
  For many purposes, it is generally useful to standardize the values of
  the similarity matrix subtending a weighted graph of interest. The use
  of this function is recommended for most analyses of weighted
  networks. In particular, these transformations should be conducted
  prior to the utilization of the cost.int.metric  and cutoff.int.metric
  functions. 
}
\value{
  \item{Matrix}{Returns a standardized matrix with large values
    representing greater similarity.}
}
\author{
  Author and maintainer: Cedric E. Ginestet <c.ginestet05@gmail.com>
}
\references{
  Ginestet, C.E. and Simmons, A. (In Press). Statistical Parametric Network Analysis of Functional
  Connectivity Dynamics during a Working Memory Task. Neuroimage.  
}
\examples{

R <- cor(cbind(rnorm(100),rnorm(100),rnorm(100),rnorm(100),rnorm(100),rnorm(100)))
print(R);
R <- metric.standardization(R)
naHeatmap(R)

}
\keyword{cost.int.metric}
\keyword{cutoff.int.metric}
