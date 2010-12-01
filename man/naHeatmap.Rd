\name{naHeatmap}
\alias{naHeatmap}
\title{Produce a heatmap visualization of a (symmetric) matrix}
\description{
      This is a tailor-made heatmap function for the NetworkAnalysis
      package, which produces by default a 'nice' heatmap of a given
      adjacency or similarity matrix.}
\usage{
naHeatmap(R,
          alpha = 0.8,
          main = "", colorkey = FALSE,
          colorkey.orientation = "bottom",
          colorscale = c("yellow", "orange", "red"),
          saving = FALSE,
          xlab = "",
          ylab = "",
          sub = "",
          bty = "o",
          at = TRUE,
          ...)
}
\arguments{
  \item{R}{A numeric matrix.}
  \item{alpha}{Numeric: Controls the alpha.regions parameter in the
    corresponding level.plot function in the lattice package. By
    default, this is set of 0.8. See the levelplot function for details.}
  \item{main}{Character: Main title of the graph.}
  \item{colorkey}{Logical: If true, a colorkey will be plotted on the
    right-hand side of the heatmap.}
  \item{colorkey.orientation}{Deprecated.}
  \item{colorscale}{Character vector: Two or more sets of colors to be
    used in the plotting of the matrix.}
  \item{saving}{Logical: If true, the levelplot function from the
    lattice package is executed with print(.) allowing for saving the
    plot to an external device.}
  \item{xlab}{Character: x-axis label.}
  \item{ylab}{Character: y-axis label.}
  \item{sub}{Character: Subtitle.}
  \item{bty}{Numeric: Type of bounding box used. See par for details.}
  \item{at}{Currently deprecated.}
  \item{\dots}{Currently deprecated.}
}
\details{
   For saving this plot to an output file, one needs to activate the
   'saving' option, by setting to TRUE. This is one of the limitations
   of the lattice package.   
}
\value{
  Does not take a value. This function is used for its side effects. 
}
\author{
  Cedric E Ginestet <c.ginestet05@gmail.com>
}
\references{
  Ginestet, C.E. and Simmons, A. (2011). Statistical Parametric Network Analysis of Functional
  Connectivity Dynamics during a Working Memory Task. Neuroimage, 5(2), 688--704. 
}
\seealso{\code{\link{cost.int.metric}}, \code{\link{lattice-package}}}
\examples{

## Generate a simple weighted graph.
R <- cor(cbind(rnorm(100),rnorm(100),rnorm(100),
               rnorm(100),rnorm(100),rnorm(100)))
R <- metric.standardization(R)

## With colorkey
naHeatmap(R,colorkey=TRUE)

## With Black and White colork scheme.
naHeatmap(R,colorkey=TRUE,colorscale=c("black","white"))

## With Black and White colork scheme, with title. 
naHeatmap(R,colorscale=c("black","white"),main="R")

## With Black and White colork scheme, with title and subtitle.
naHeatmap(R<.5,colorscale=c("black","white"),main="R",
          sub="Thresholded correlation matrix")

## With Black and White colork scheme, with title
## and subtitle and x- and y- labels.
naHeatmap(R<.5,colorscale=c("black","white"),
          main="R", xlab="Vertices",  ylab="Vertices", 
          sub="Thresholded correlation matrix")
}
\keyword{heatmap}
