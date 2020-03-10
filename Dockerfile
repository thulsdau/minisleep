FROM scratch
COPY sleep /bin/
ENTRYPOINT ["/bin/sleep"]
CMD ["10"]
