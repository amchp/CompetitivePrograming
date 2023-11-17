from mrjob.job import MRJob
from mrjob.step import MRStep

class MRSalaryPerEmployee(MRJob):

    def steps(self):
        return [
            MRStep(mapper=self.mapper,
                   reducer=self.reducer),
        ]

    def mapper(self, _, line):
        for w in line.split():
            yield w,1

    def reducer(self, key, values):
        yield key, sum(values)

if __name__ == '__main__':
    MRSalaryPerEmployee.run()