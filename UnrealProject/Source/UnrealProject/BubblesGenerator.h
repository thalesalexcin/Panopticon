// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/ActorComponent.h"
#include "BubblesGenerator.generated.h"

UENUM(BlueprintType, Category = "Generation")
enum class EBubbleType
{
	Animals =		0 UMETA(DisplayName = "Animals"),
	Food =			1 UMETA(DisplayName = "Food"),
	Games =			2 UMETA(DisplayName = "Games"),
	Meteorology =	3 UMETA(DisplayName = "Meteorology"),
	Money =			4 UMETA(DisplayName = "Money"),
	Puzzle =		5 UMETA(DisplayName = "Puzzle"),
	Recycle =		6 UMETA(DisplayName = "Recycle"),
	Studys =		7 UMETA(DisplayName = "Studys")
};

USTRUCT(BlueprintType, Category = "Generation")
struct FBubbleWeight
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation")
	TEnumAsByte<EBubbleType> BubbleType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation")
	uint8 Weight;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALPROJECT_API UBubblesGenerator : public UActorComponent
{
	GENERATED_BODY()

public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation")
	uint8  Row = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation")
	uint8 Column = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation")
	float _BubbleSize = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation")
	UStaticMeshComponent* Ground;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation")
	FVector boundsMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation")
	FVector boundsMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation")
	UObject* Bubble;
	
	UFUNCTION(BlueprintCallable, Category = "Generation")
	FVector getSpawnPos(int X, int Y);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generation")
	TArray<FBubbleWeight> BubbleWeights;


	UFUNCTION(BlueprintCallable, Category = "Generation")
	EBubbleType getPicto();

	// Sets default values for this component's properties
	UBubblesGenerator();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:
	bool setCells = true;
	float _CellWidth;
	float _CellHeigth;
	FVector2D** cells;
	EBubbleType* typeWeightedList;
	int SumBubbleWeights = 0;

};