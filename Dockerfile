# Dockerfile to package static sleep binary in absoulte minimal container
# Will sleep for 31+ years by default
FROM scratch
COPY sleep /bin/
CMD ["/bin/sleep","1000000000"]
