Include(FetchContent)

############################################
# Catch2

message("Fetching Catch2...")

FetchContent_Declare(
  Catch2
  URL https://github.com/catchorg/Catch2/archive/refs/tags/v3.4.0.tar.gz
)

FetchContent_MakeAvailable(Catch2)
