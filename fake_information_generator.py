# Fake information generator

from faker import Faker

fake = Faker()

print("Name: " + fake.name())
print("Email: " + fake.email())
print("Country: " + fake.country())
print()

print(fake.profile())                                                        
