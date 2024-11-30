-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Nov 29, 2024 at 02:07 PM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.0.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `storylines`
--

-- --------------------------------------------------------

--
-- Table structure for table `ajail_logs`
--

CREATE TABLE `ajail_logs` (
  `id` int(11) NOT NULL,
  `JailedDBID` int(11) NOT NULL,
  `JailedName` varchar(32) NOT NULL,
  `Reason` varchar(128) NOT NULL,
  `Date` varchar(90) NOT NULL,
  `JailedBy` varchar(32) NOT NULL,
  `Time` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Table structure for table `bannedlist`
--

CREATE TABLE `bannedlist` (
  `id` int(11) NOT NULL,
  `CharacterDBID` int(11) NOT NULL,
  `MasterDBID` int(11) NOT NULL,
  `CharacterName` varchar(32) NOT NULL,
  `Reason` varchar(128) NOT NULL,
  `Date` varchar(90) NOT NULL,
  `BannedBy` varchar(32) NOT NULL,
  `IpAddress` varchar(60) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Table structure for table `ban_logs`
--

CREATE TABLE `ban_logs` (
  `id` int(11) NOT NULL,
  `CharacterDBID` int(11) NOT NULL,
  `MasterDBID` int(11) NOT NULL,
  `CharacterName` varchar(32) NOT NULL,
  `Reason` varchar(128) NOT NULL,
  `BannedBy` varchar(32) NOT NULL,
  `Date` varchar(90) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Table structure for table `businesses`
--

CREATE TABLE `businesses` (
  `BusinessDBID` int(11) NOT NULL,
  `BusinessOwnerDBID` int(11) NOT NULL DEFAULT 0,
  `BusinessInteriorX` float NOT NULL DEFAULT 0,
  `BusinessInteriorY` float NOT NULL DEFAULT 0,
  `BusinessInteriorZ` float NOT NULL DEFAULT 0,
  `BusinessInteriorWorld` int(11) NOT NULL DEFAULT 0,
  `BusinessInteriorIntID` int(11) NOT NULL DEFAULT 0,
  `BusinessEntranceX` float NOT NULL DEFAULT 0,
  `BusinessEntranceY` float NOT NULL DEFAULT 0,
  `BusinessEntranceZ` float NOT NULL DEFAULT 0,
  `BusinessName` varchar(90) NOT NULL DEFAULT 'Nameless',
  `BusinessType` int(11) NOT NULL DEFAULT 0,
  `BusinessLocked` tinyint(1) NOT NULL DEFAULT 0,
  `BusinessEntranceFee` int(11) NOT NULL DEFAULT 1,
  `BusinessLevel` int(11) NOT NULL DEFAULT 0,
  `BusinessMarketPrice` int(11) NOT NULL DEFAULT 5000,
  `BusinessCashbox` int(11) NOT NULL DEFAULT 0,
  `BusinessStock` int(11) NOT NULL DEFAULT 0,
  `BusinessMapIcon` int(11) NOT NULL DEFAULT 0,
  `BusinessPointX` float NOT NULL DEFAULT 0,
  `BusinessPointY` float NOT NULL DEFAULT 0,
  `BusinessPointZ` float NOT NULL DEFAULT 0,
  `BusinessRobberyTime` int(11) NOT NULL DEFAULT 0,
  `BusinessShipments` int(11) NOT NULL DEFAULT 0,
  `BusinessAmount` int(11) NOT NULL DEFAULT 0,
  `BusinessFuelX` float NOT NULL DEFAULT 0,
  `BusinessFuelY` float NOT NULL DEFAULT 0,
  `BusinessFuelZ` float NOT NULL DEFAULT 0,
  `BusinessActorX` float NOT NULL DEFAULT 0,
  `BusinessActorY` float NOT NULL DEFAULT 0,
  `BusinessActorZ` float NOT NULL DEFAULT 0,
  `BusinessActorA` float NOT NULL DEFAULT 0,
  `BusinessProducts1` int(11) NOT NULL DEFAULT 0,
  `BusinessProducts2` int(11) NOT NULL DEFAULT 0,
  `BusinessProducts3` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `businesses`
--

INSERT INTO `businesses` (`BusinessDBID`, `BusinessOwnerDBID`, `BusinessInteriorX`, `BusinessInteriorY`, `BusinessInteriorZ`, `BusinessInteriorWorld`, `BusinessInteriorIntID`, `BusinessEntranceX`, `BusinessEntranceY`, `BusinessEntranceZ`, `BusinessName`, `BusinessType`, `BusinessLocked`, `BusinessEntranceFee`, `BusinessLevel`, `BusinessMarketPrice`, `BusinessCashbox`, `BusinessStock`, `BusinessMapIcon`, `BusinessPointX`, `BusinessPointY`, `BusinessPointZ`, `BusinessRobberyTime`, `BusinessShipments`, `BusinessAmount`, `BusinessFuelX`, `BusinessFuelY`, `BusinessFuelZ`, `BusinessActorX`, `BusinessActorY`, `BusinessActorZ`, `BusinessActorA`, `BusinessProducts1`, `BusinessProducts2`, `BusinessProducts3`) VALUES
(15, 0, 1470.7, 1562.97, 108.377, 8030, 11, 1248.68, 365.039, 19.5547, 'Unknown', 4, 0, 0, 0, 0, 0, 0, 0, 1473.9, 1567.96, 108.377, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(16, 0, 1439.55, 1562.97, 108.377, 16013, 11, 122.412, -294.581, 1.57812, 'Unknown', 3, 0, 0, 0, 0, 0, 0, 0, 1440.35, 1576.02, 108.377, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(17, 0, 207.726, -110.823, 1005.13, 4937, 15, 2244.5, -1665.01, 15.4766, 'Unknown', 8, 0, 0, 0, 5000000, 0, 95, 45, 207.742, -99.5688, 1005.35, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(18, 0, 0, 0, 0, 6830, 0, 1929.55, -1776.22, 13.5469, 'Unknown', 7, 0, 0, 0, 5000000, 0, 0, 35, 0, 0, 0, 0, 0, 0, 1938.73, -1773.93, 13.3828, 0, 0, 0, 0, 0, 0, 0),
(19, 0, 0, 0, 0, 17149, 0, 1268.33, -1547.47, 13.5606, 'Departement of Motorvehicle', 10, 0, 0, 0, 0, 0, 0, 36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(20, 0, 0, 0, 0, 1605, 0, 1671.55, -2313.43, -2.65855, 'Los Santos Rental', 12, 0, 0, 0, 0, 0, 0, 37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(21, 0, 501.978, -67.9858, 998.758, 11600, 11, 2310.08, -1643.53, 14.827, 'Ganton Bar', 2, 0, 0, 0, 5000000, 0, 99, 49, 496.994, -76.7572, 998.855, 0, 0, 0, 0, 0, 0, 497.305, -77.5615, 998.765, 2.79407, 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `characters`
--

CREATE TABLE `characters` (
  `master_dbid` int(11) NOT NULL,
  `char_dbid` int(11) NOT NULL,
  `char_name` varchar(32) NOT NULL DEFAULT 'None',
  `char_masters` varchar(32) NOT NULL DEFAULT 'None',
  `create_date` varchar(60) NOT NULL DEFAULT 'None',
  `create_ip` varchar(60) NOT NULL DEFAULT 'None',
  `pAdmin` int(4) NOT NULL DEFAULT 0,
  `pLastSkin` int(11) NOT NULL DEFAULT 0,
  `pFacSkin` int(11) NOT NULL DEFAULT 0,
  `pLastPosX` float NOT NULL DEFAULT 1642.02,
  `pLastPosY` float NOT NULL DEFAULT -2334.05,
  `pLastPosZ` float NOT NULL DEFAULT 13.5469,
  `pLastInterior` int(11) NOT NULL DEFAULT 0,
  `pLastWorld` int(11) NOT NULL DEFAULT 0,
  `pLevel` int(11) NOT NULL DEFAULT 1,
  `pWantedLevel` int(11) NOT NULL DEFAULT 0,
  `pEXP` int(11) NOT NULL DEFAULT 0,
  `pAge` int(11) NOT NULL DEFAULT 18,
  `pHeight` int(11) NOT NULL DEFAULT 0,
  `pEthnicity` varchar(32) NOT NULL DEFAULT 'Invalid',
  `pHair` varchar(32) NOT NULL DEFAULT 'Invalid',
  `pEyes` varchar(32) NOT NULL DEFAULT 'Invalid',
  `pDescription` varchar(32) NOT NULL DEFAULT 'Invalid',
  `pGender` int(11) NOT NULL DEFAULT 0,
  `pStory` varchar(90) NOT NULL DEFAULT 'Nothing',
  `pStoryTwo` varchar(90) NOT NULL DEFAULT 'Nothing',
  `pMoney` int(11) NOT NULL DEFAULT 250,
  `pBank` int(11) NOT NULL DEFAULT 250,
  `pPaycheck` int(11) NOT NULL DEFAULT 0,
  `pPhone` int(11) NOT NULL DEFAULT 0,
  `pLastOnline` varchar(90) NOT NULL DEFAULT 'None',
  `pLastOnlineTime` int(11) NOT NULL DEFAULT 0,
  `pAdminjailed` tinyint(1) NOT NULL DEFAULT 0,
  `pAdminJailTime` int(11) NOT NULL DEFAULT 0,
  `pOfflinejailed` tinyint(1) NOT NULL DEFAULT 0,
  `pOfflinejailedReason` varchar(128) NOT NULL DEFAULT 'None',
  `pFaction` int(11) NOT NULL DEFAULT 0,
  `pFactionRank` int(11) NOT NULL DEFAULT 0,
  `pFactionSubsets` int(11) NOT NULL DEFAULT 0,
  `pOwnedVehicles1` int(11) NOT NULL DEFAULT 0,
  `pOwnedVehicles2` int(11) NOT NULL DEFAULT 0,
  `pOwnedVehicles3` int(11) NOT NULL DEFAULT 0,
  `pOwnedVehicles4` int(11) NOT NULL DEFAULT 0,
  `pOwnedVehicles5` int(11) NOT NULL DEFAULT 0,
  `pVehicleSpawned` tinyint(1) NOT NULL DEFAULT 0,
  `pVehicleSpawnedID` int(11) NOT NULL DEFAULT 0,
  `pTimeplayed` int(11) NOT NULL DEFAULT 0,
  `pMaskID` int(11) NOT NULL DEFAULT 0,
  `pMaskIDEx` int(11) NOT NULL DEFAULT 0,
  `pInProperty` int(11) NOT NULL DEFAULT 0,
  `pInBusiness` int(11) NOT NULL DEFAULT 0,
  `pInEntrance` int(11) NOT NULL DEFAULT 0,
  `pRadio1` int(11) NOT NULL DEFAULT 0,
  `pRadio2` int(11) NOT NULL DEFAULT 0,
  `pMainSlot` int(11) NOT NULL DEFAULT 1,
  `pSpawnPoint` int(11) NOT NULL DEFAULT 0,
  `pSpawnPointHouse` int(11) NOT NULL DEFAULT 0,
  `pWeaponsLicense` int(11) NOT NULL DEFAULT 0,
  `pDriversLicense` int(11) NOT NULL DEFAULT 0,
  `pTruckerLicense` int(11) NOT NULL DEFAULT 0,
  `pActiveListings` int(11) NOT NULL DEFAULT 0,
  `pPrisonTimes` int(11) NOT NULL DEFAULT 0,
  `pPrison` tinyint(1) NOT NULL DEFAULT 0,
  `pInFaction` int(11) NOT NULL DEFAULT 0,
  `pRobberyCooldown` int(11) NOT NULL DEFAULT 0,
  `pFightstyle` int(11) NOT NULL DEFAULT 4,
  `pHasAoe` int(11) NOT NULL DEFAULT 0,
  `pHasInjured` tinyint(1) NOT NULL DEFAULT 0,
  `pHasDeath` tinyint(1) NOT NULL DEFAULT 0,
  `pHealth` float NOT NULL DEFAULT 100,
  `pMaxHealth` float NOT NULL DEFAULT 100,
  `pArmor` float NOT NULL DEFAULT 0,
  `pToggleAdmin` tinyint(1) NOT NULL DEFAULT 0,
  `pToggleHUD` tinyint(1) NOT NULL DEFAULT 0,
  `pToggleJoined` tinyint(1) NOT NULL DEFAULT 0,
  `pBodyPart1` int(11) NOT NULL DEFAULT 100,
  `pBodyPart2` int(11) NOT NULL DEFAULT 100,
  `pBodyPart3` int(11) NOT NULL DEFAULT 100,
  `pBodyPart4` int(11) NOT NULL DEFAULT 100,
  `pBodyPart5` int(11) NOT NULL DEFAULT 100,
  `pBodyPart6` int(11) NOT NULL DEFAULT 100,
  `pBodyPart7` int(11) NOT NULL DEFAULT 100,
  `pBodyPart8` int(11) NOT NULL DEFAULT 100,
  `pWound1` int(11) NOT NULL DEFAULT 0,
  `pWound2` int(11) NOT NULL DEFAULT 0,
  `pWound3` int(11) NOT NULL DEFAULT 0,
  `pWound4` int(11) NOT NULL DEFAULT 0,
  `pWound5` int(11) NOT NULL DEFAULT 0,
  `pWound6` int(11) NOT NULL DEFAULT 0,
  `pWound7` int(11) NOT NULL DEFAULT 0,
  `pWound8` int(11) NOT NULL DEFAULT 0,
  `pJobs` int(11) NOT NULL DEFAULT 0,
  `pJobsCD` int(11) NOT NULL DEFAULT 0,
  `pSweeperCD` int(11) NOT NULL DEFAULT 0,
  `pGarbageCD` int(11) NOT NULL DEFAULT 0,
  `pBusdriverCD` int(11) NOT NULL DEFAULT 0,
  `pTutorial` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `characters`
--

INSERT INTO `characters` (`master_dbid`, `char_dbid`, `char_name`, `char_masters`, `create_date`, `create_ip`, `pAdmin`, `pLastSkin`, `pFacSkin`, `pLastPosX`, `pLastPosY`, `pLastPosZ`, `pLastInterior`, `pLastWorld`, `pLevel`, `pWantedLevel`, `pEXP`, `pAge`, `pHeight`, `pEthnicity`, `pHair`, `pEyes`, `pDescription`, `pGender`, `pStory`, `pStoryTwo`, `pMoney`, `pBank`, `pPaycheck`, `pPhone`, `pLastOnline`, `pLastOnlineTime`, `pAdminjailed`, `pAdminJailTime`, `pOfflinejailed`, `pOfflinejailedReason`, `pFaction`, `pFactionRank`, `pFactionSubsets`, `pOwnedVehicles1`, `pOwnedVehicles2`, `pOwnedVehicles3`, `pOwnedVehicles4`, `pOwnedVehicles5`, `pVehicleSpawned`, `pVehicleSpawnedID`, `pTimeplayed`, `pMaskID`, `pMaskIDEx`, `pInProperty`, `pInBusiness`, `pInEntrance`, `pRadio1`, `pRadio2`, `pMainSlot`, `pSpawnPoint`, `pSpawnPointHouse`, `pWeaponsLicense`, `pDriversLicense`, `pTruckerLicense`, `pActiveListings`, `pPrisonTimes`, `pPrison`, `pInFaction`, `pRobberyCooldown`, `pFightstyle`, `pHasAoe`, `pHasInjured`, `pHasDeath`, `pHealth`, `pMaxHealth`, `pArmor`, `pToggleAdmin`, `pToggleHUD`, `pToggleJoined`, `pBodyPart1`, `pBodyPart2`, `pBodyPart3`, `pBodyPart4`, `pBodyPart5`, `pBodyPart6`, `pBodyPart7`, `pBodyPart8`, `pWound1`, `pWound2`, `pWound3`, `pWound4`, `pWound5`, `pWound6`, `pWound7`, `pWound8`, `pJobs`, `pJobsCD`, `pSweeperCD`, `pGarbageCD`, `pBusdriverCD`, `pTutorial`) VALUES
(18, 1, 'Jayvon_Williams', 'Radeetz', 'June 2, 2024 11:49:50', '127.0.0.1', 4, 184, 20263, 1513.49, -1839.28, 13.5469, 0, 0, 10, 1, 2, 25, 0, 'Los Santos', 'Invalid', 'Invalid', 'Invalid', 1, '', '', 17300, 254, 1002, 94367, 'November 29, 2024 20:03:27', 19, 0, 0, 0, 'a', 1, 4, 2, 94, 0, 0, 0, 0, 1, 43, 63, 205458, 58, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 15, 1, 0, 0, 100, 100, 0, 0, 0, 0, 0, 100, 100, 100, 100, 1, 100, 0, 1, 100, 69, 100, 100, 100, 75, 100, 2, 0, 0, 0, 0, 1),
(60, 53, 'Delilah_Winters', 'Delilah', 'November 6, 2024 19:47:32', '127.0.0.1', 4, 245, 0, 508.632, -84.4331, 998.961, 11, 11600, 1, 0, 0, 2, 0, 'Los santos', 'Invalid', 'Invalid', 'Invalid', 2, '', '', 4955250, 250, 0, 100621, 'November 26, 2024 16:59:50', 0, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 236393, 0, 0, 7, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 96, 100, 0, 0, 0, 0, 73, 100, 100, 100, 100, 100, 100, 100, 1, 100, 100, 100, 100, 100, 100, 0, 3, 0, 0, 0, 0, 1),
(18, 56, 'Ethan_Patterson', 'Radeetz', 'November 28, 2024 21:59:13', '127.0.0.1', 0, 106, 0, 1685.62, -2334.3, -2.17969, 11, 0, 1, 0, 0, 17, 177, 'Black', 'Brown', 'Gray', 'Invalid', 1, '', '', 250, 250, 0, 96576, 'November 28, 2024 22:02:34', 0, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 212894, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(18, 57, 'Bryan_DeOrtiz', 'Radeetz', 'November 28, 2024 22:04:10', '127.0.0.1', 0, 61, 0, 1685.55, -2330.55, -2.67969, 0, 0, 1, 0, 0, 40, 187, 'Asian', 'Black', 'Amber', 'Invalid', 1, '', '', 250, 250, 0, 100024, 'November 28, 2024 22:05:04', 2, 0, 0, 0, 'None', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 357431, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 1, 0, 0, 100, 100, 0, 0, 0, 0, 100, 100, 100, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1);

-- --------------------------------------------------------

--
-- Table structure for table `contacts`
--

CREATE TABLE `contacts` (
  `ID` int(11) NOT NULL DEFAULT 0,
  `contactName` varchar(32) NOT NULL DEFAULT 'none',
  `contactID` int(11) NOT NULL DEFAULT 0,
  `contactNumber` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `court`
--

CREATE TABLE `court` (
  `ID` int(11) NOT NULL,
  `ballx` float NOT NULL DEFAULT 0,
  `bally` float NOT NULL DEFAULT 0,
  `ballz` float NOT NULL DEFAULT 0,
  `bluex` float NOT NULL DEFAULT 0,
  `bluey` float NOT NULL DEFAULT 0,
  `bluez` float NOT NULL DEFAULT 0,
  `redx` float NOT NULL DEFAULT 0,
  `redy` float NOT NULL DEFAULT 0,
  `redz` float NOT NULL DEFAULT 0,
  `bluebx` float NOT NULL DEFAULT 0,
  `blueby` float NOT NULL DEFAULT 0,
  `bluebz` float NOT NULL DEFAULT 0,
  `redbx` float NOT NULL DEFAULT 0,
  `redby` float NOT NULL DEFAULT 0,
  `redbz` float NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `court`
--

INSERT INTO `court` (`ID`, `ballx`, `bally`, `ballz`, `bluex`, `bluey`, `bluez`, `redx`, `redy`, `redz`, `bluebx`, `blueby`, `bluebz`, `redbx`, `redby`, `redbz`) VALUES
(3, 2316.91, -1527.57, 24.544, 2317, -1539.97, 24.344, 2317.02, -1515.59, 24.344, 2317.01, -1541.1, 27.364, 2316.87, -1514.77, 27.394),
(4, 2290.52, -1528.25, 26.075, 2290.6, -1540.91, 26.075, 2290.61, -1514.93, 26.075, 2290.7, -1541.11, 28.945, 2290.49, -1514.8, 28.875),
(5, 2782.18, -2019.61, 12.755, 2794.68, -2019.58, 12.755, 2769.08, -2019.6, 12.755, 2794.99, -2019.52, 15.445, 2768.69, -2019.7, 15.425),
(6, 2045.32, -1690.38, 12.755, 2045.58, -1687.72, 12.755, 0, 0, 0, 2045.47, -1687.73, 15.677, 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `criminal_record`
--

CREATE TABLE `criminal_record` (
  `idx` int(11) NOT NULL,
  `player_name` varchar(32) NOT NULL DEFAULT 'None',
  `charge_reason` varchar(128) NOT NULL DEFAULT 'None',
  `add_date` varchar(90) NOT NULL DEFAULT 'None'
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `criminal_record`
--

INSERT INTO `criminal_record` (`idx`, `player_name`, `charge_reason`, `add_date`) VALUES
(22, 'Radeetz', 'lorem ipsum', 'July 10, 2024 20:51:57'),
(23, 'Blixkyy', 'Grand Theft Auto', 'July 11, 2024 11:54:27'),
(24, 'Jayvon_Williams', 'Sex Harrasment', 'November 29, 2024 19:35:33');

-- --------------------------------------------------------

--
-- Table structure for table `dropped`
--

CREATE TABLE `dropped` (
  `ID` int(12) NOT NULL,
  `itemName` varchar(32) DEFAULT NULL,
  `itemModel` int(12) DEFAULT 0,
  `itemX` float DEFAULT 0,
  `itemY` float DEFAULT 0,
  `itemZ` float DEFAULT 0,
  `itemRX` float DEFAULT 0,
  `itemRY` float DEFAULT 0,
  `itemRZ` float DEFAULT 0,
  `itemInt` int(12) DEFAULT 0,
  `itemWorld` int(12) DEFAULT 0,
  `itemQuantity` int(12) DEFAULT 0,
  `itemAmount` int(12) DEFAULT 0,
  `itemType` int(12) DEFAULT 0,
  `itemPlayer` varchar(24) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Table structure for table `entrance`
--

CREATE TABLE `entrance` (
  `ID` int(11) NOT NULL,
  `posx` float NOT NULL DEFAULT 0,
  `posy` float NOT NULL DEFAULT 0,
  `posz` float NOT NULL DEFAULT 0,
  `intx` float NOT NULL DEFAULT 0,
  `inty` float NOT NULL DEFAULT 0,
  `intz` float NOT NULL DEFAULT 0,
  `interior` int(11) NOT NULL DEFAULT 0,
  `world` int(11) NOT NULL DEFAULT 0,
  `icon` int(11) NOT NULL DEFAULT 0,
  `garage` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `entrance`
--

INSERT INTO `entrance` (`ID`, `posx`, `posy`, `posz`, `intx`, `inty`, `intz`, `interior`, `world`, `icon`, `garage`) VALUES
(1, 1554.81, -1675.61, 16.1953, 246.771, 62.628, 1003.64, 6, 24518, 30, 0),
(2, 2034.05, -1402.26, 17.2936, 1849.65, -1072.56, 41.6537, 1, 15241, 22, 0),
(3, 1798.07, -1578.85, 14.0916, 1260.11, 896.423, 1161.1, 6, 3028, 40, 0),
(4, 1172.66, -1323.34, 15.4025, 1266.56, -1291.42, 1061.15, 6, 16034, 22, 0);

-- --------------------------------------------------------

--
-- Table structure for table `factions`
--

CREATE TABLE `factions` (
  `DBID` int(11) NOT NULL,
  `FactionName` varchar(90) NOT NULL DEFAULT 'None',
  `FactionAbbrev` varchar(30) NOT NULL DEFAULT 'None',
  `FactionSpawnX` float NOT NULL DEFAULT 0,
  `FactionSpawnY` float NOT NULL DEFAULT 0,
  `FactionSpawnZ` float NOT NULL DEFAULT 0,
  `FactionInterior` int(11) NOT NULL DEFAULT 0,
  `FactionWorld` int(11) NOT NULL DEFAULT 0,
  `FactionJoinRank` int(11) NOT NULL DEFAULT 0,
  `FactionAlterRank` int(11) NOT NULL DEFAULT 0,
  `FactionChatRank` int(11) NOT NULL DEFAULT 0,
  `FactionTowRank` int(11) NOT NULL DEFAULT 0,
  `FactionChatColor` int(11) NOT NULL DEFAULT 0,
  `FactionType` tinyint(4) NOT NULL DEFAULT 0,
  `FactionInteriorId` int(11) NOT NULL DEFAULT 0,
  `FactionInteriorWorld` int(11) NOT NULL DEFAULT 0,
  `FactionTurfTokens` int(11) NOT NULL DEFAULT 0,
  `FactionDrugs` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `factions`
--

INSERT INTO `factions` (`DBID`, `FactionName`, `FactionAbbrev`, `FactionSpawnX`, `FactionSpawnY`, `FactionSpawnZ`, `FactionInterior`, `FactionWorld`, `FactionJoinRank`, `FactionAlterRank`, `FactionChatRank`, `FactionTowRank`, `FactionChatColor`, `FactionType`, `FactionInteriorId`, `FactionInteriorWorld`, `FactionTurfTokens`, `FactionDrugs`) VALUES
(4, 'San Andreas Police Departement', 'SAPD', 1546.82, -1668.81, 13.5665, 0, 0, 0, 0, 0, 0, -1920073729, 2, 6, 0, 1, 30),
(5, 'San Andreas Medical Departement', 'SAMD', 1184.09, -1333.22, 13.5804, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 1, 30);

-- --------------------------------------------------------

--
-- Table structure for table `faction_ranks`
--

CREATE TABLE `faction_ranks` (
  `factionid` int(11) NOT NULL,
  `FactionRank1` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank2` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank3` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank4` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank5` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank6` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank7` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank8` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank9` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank10` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank11` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank12` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank13` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank14` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank15` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank16` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank17` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank18` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank19` varchar(60) NOT NULL DEFAULT 'NotSet',
  `FactionRank20` varchar(60) NOT NULL DEFAULT 'NotSet'
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `faction_ranks`
--

INSERT INTO `faction_ranks` (`factionid`, `FactionRank1`, `FactionRank2`, `FactionRank3`, `FactionRank4`, `FactionRank5`, `FactionRank6`, `FactionRank7`, `FactionRank8`, `FactionRank9`, `FactionRank10`, `FactionRank11`, `FactionRank12`, `FactionRank13`, `FactionRank14`, `FactionRank15`, `FactionRank16`, `FactionRank17`, `FactionRank18`, `FactionRank19`, `FactionRank20`) VALUES
(15, 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet', 'NotSet');

-- --------------------------------------------------------

--
-- Table structure for table `furniture`
--

CREATE TABLE `furniture` (
  `id` int(11) NOT NULL,
  `propertydbid` int(11) DEFAULT 0,
  `modelid` smallint(5) DEFAULT 0,
  `name` varchar(32) DEFAULT 'None',
  `price` int(10) DEFAULT 0,
  `type` int(11) NOT NULL DEFAULT 0,
  `pos_x` float DEFAULT 0,
  `pos_y` float DEFAULT 0,
  `pos_z` float DEFAULT 0,
  `rot_x` float DEFAULT 0,
  `rot_y` float DEFAULT 0,
  `rot_z` float DEFAULT 0,
  `interior` tinyint(2) DEFAULT 0,
  `world` int(10) DEFAULT 0,
  `door_opened` tinyint(1) DEFAULT 0,
  `door_locked` tinyint(1) DEFAULT 0,
  `matModel0` int(11) NOT NULL DEFAULT 0,
  `matModel1` int(11) NOT NULL DEFAULT 0,
  `matModel2` int(11) NOT NULL DEFAULT 0,
  `matModel3` int(11) NOT NULL DEFAULT 0,
  `matModel4` int(11) NOT NULL DEFAULT 0,
  `matModel5` int(11) NOT NULL DEFAULT 0,
  `matModel6` int(11) NOT NULL DEFAULT 0,
  `matModel7` int(11) NOT NULL DEFAULT 0,
  `matModel8` int(11) NOT NULL DEFAULT 0,
  `matModel9` int(11) NOT NULL DEFAULT 0,
  `matModel10` int(11) NOT NULL DEFAULT 0,
  `matModel11` int(11) NOT NULL DEFAULT 0,
  `matModel12` int(11) NOT NULL DEFAULT 0,
  `matModel13` int(11) NOT NULL DEFAULT 0,
  `matModel14` int(11) NOT NULL DEFAULT 0,
  `matTxd0` varchar(32) NOT NULL DEFAULT 'None',
  `matTxd1` varchar(32) NOT NULL DEFAULT 'None',
  `matTxd2` varchar(32) NOT NULL DEFAULT 'None',
  `matTxd3` varchar(32) NOT NULL DEFAULT 'None',
  `matTxd4` varchar(32) NOT NULL DEFAULT 'None',
  `matTxd5` varchar(32) NOT NULL DEFAULT 'None',
  `matTxd6` varchar(32) NOT NULL DEFAULT 'None',
  `matTxd7` varchar(32) NOT NULL DEFAULT 'None',
  `matTxd8` varchar(32) NOT NULL DEFAULT 'None',
  `matTxd9` varchar(32) NOT NULL DEFAULT 'None',
  `matTxd10` varchar(32) NOT NULL DEFAULT 'None',
  `matTxd11` varchar(32) NOT NULL DEFAULT 'None',
  `matTxd12` varchar(32) NOT NULL DEFAULT 'None',
  `matTxd13` varchar(32) NOT NULL DEFAULT 'None',
  `matTxd14` varchar(32) NOT NULL DEFAULT 'None',
  `matTexture0` varchar(32) NOT NULL,
  `matTexture1` varchar(32) NOT NULL DEFAULT 'None',
  `matTexture2` varchar(32) NOT NULL DEFAULT 'None',
  `matTexture3` varchar(32) NOT NULL DEFAULT 'None',
  `matTexture4` varchar(32) NOT NULL DEFAULT 'None',
  `matTexture5` varchar(32) NOT NULL DEFAULT 'None',
  `matTexture6` varchar(32) NOT NULL DEFAULT 'None',
  `matTexture7` varchar(32) NOT NULL DEFAULT 'None',
  `matTexture8` varchar(32) NOT NULL DEFAULT 'None',
  `matTexture9` varchar(32) NOT NULL DEFAULT 'None',
  `matTexture10` varchar(32) NOT NULL,
  `matTexture11` varchar(32) NOT NULL DEFAULT 'None',
  `matTexture12` varchar(32) NOT NULL DEFAULT 'None',
  `matTexture13` varchar(32) NOT NULL DEFAULT 'None',
  `matTexture14` varchar(32) NOT NULL DEFAULT 'None'
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `furniture`
--

INSERT INTO `furniture` (`id`, `propertydbid`, `modelid`, `name`, `price`, `type`, `pos_x`, `pos_y`, `pos_z`, `rot_x`, `rot_y`, `rot_z`, `interior`, `world`, `door_opened`, `door_locked`, `matModel0`, `matModel1`, `matModel2`, `matModel3`, `matModel4`, `matModel5`, `matModel6`, `matModel7`, `matModel8`, `matModel9`, `matModel10`, `matModel11`, `matModel12`, `matModel13`, `matModel14`, `matTxd0`, `matTxd1`, `matTxd2`, `matTxd3`, `matTxd4`, `matTxd5`, `matTxd6`, `matTxd7`, `matTxd8`, `matTxd9`, `matTxd10`, `matTxd11`, `matTxd12`, `matTxd13`, `matTxd14`, `matTexture0`, `matTexture1`, `matTexture2`, `matTexture3`, `matTexture4`, `matTexture5`, `matTexture6`, `matTexture7`, `matTexture8`, `matTexture9`, `matTexture10`, `matTexture11`, `matTexture12`, `matTexture13`, `matTexture14`) VALUES
(82, 42, 19379, 'Wall Static', 0, 1, 330.005, 458.411, 996.813, 0, 90, 0, 8, 38926, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(83, 42, 19449, 'Wall Static', 0, 1, 334.523, 448.788, 998.619, 0, -0.000007, 180, 8, 38926, 0, 0, 14792, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'ab_vgsgymbits01', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'bbar_wall2', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(84, 42, 19379, 'Wall Static', 0, 1, 330.005, 448.791, 1000.44, 0, 90, 0, 8, 38926, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(85, 42, 19379, 'Wall Static', 0, 1, 330.005, 458.411, 1000.44, 0, 90, 0, 8, 38926, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(86, 42, 19449, 'Wall Static', 0, 1, 334.523, 458.408, 998.619, 0, -0.000007, 180, 8, 38926, 0, 0, 14792, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'ab_vgsgymbits01', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'bbar_wall2', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(87, 42, 19449, 'Wall Static', 0, 1, 324.834, 458.407, 998.619, 0, 0, 180, 8, 38926, 0, 0, 14792, 14792, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'ab_vgsgymbits01', 'ab_vgsgymbits01', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'bbar_wall2', 'bbar_wall2', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(88, 42, 19449, 'Wall Static', 0, 1, 324.834, 448.788, 998.619, 0, 0, 180, 8, 38926, 0, 0, 14792, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'ab_vgsgymbits01', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'bbar_wall2', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(89, 42, 19379, 'Wall Static', 0, 1, 330.005, 448.791, 996.813, 0, 90, 0, 8, 38926, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(90, 42, 19449, 'Wall Static', 0, 1, 329.734, 463.137, 998.619, 0, 0, 270, 8, 38926, 0, 0, 14792, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'ab_vgsgymbits01', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'bbar_wall2', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(91, 42, 19449, 'Wall Static', 0, 1, 329.734, 444.058, 998.619, 0, 0, 270, 8, 38926, 0, 0, 14792, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'ab_vgsgymbits01', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'bbar_wall2', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None'),
(92, 42, 19802, 'Door Static', 0, 1, 328.981, 463.07, 996.899, 0, 0, 360, 8, 38926, 0, 0, 19486, 19486, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'burgalrystore_sfse', 'burgalrystore_sfse', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'Bow_LoadingBayDoor', 'Bow_LoadingBayDoor', 'None', 'None', 'None', 'None', 'None', 'None', 'None', 'None', '', 'None', 'None', 'None', 'None');

-- --------------------------------------------------------

--
-- Table structure for table `gates`
--

CREATE TABLE `gates` (
  `dbid` int(11) NOT NULL,
  `modelid` int(11) NOT NULL DEFAULT 0,
  `interior` int(11) NOT NULL DEFAULT 0,
  `world` int(11) NOT NULL DEFAULT 0,
  `faction` int(11) NOT NULL DEFAULT 0,
  `status` int(11) NOT NULL DEFAULT 0,
  `posx` float NOT NULL DEFAULT 0,
  `posy` float NOT NULL DEFAULT 0,
  `posz` float NOT NULL DEFAULT 0,
  `posrx` float NOT NULL DEFAULT 0,
  `posry` float NOT NULL DEFAULT 0,
  `posrz` float NOT NULL DEFAULT 0,
  `movex` float NOT NULL DEFAULT 0,
  `movey` float NOT NULL DEFAULT 0,
  `movez` float NOT NULL DEFAULT 0,
  `moverx` float NOT NULL DEFAULT 0,
  `movery` float NOT NULL DEFAULT 0,
  `moverz` float NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `gates`
--

INSERT INTO `gates` (`dbid`, `modelid`, `interior`, `world`, `faction`, `status`, `posx`, `posy`, `posz`, `posrx`, `posry`, `posrz`, `movex`, `movey`, `movez`, `moverx`, `movery`, `moverz`) VALUES
(9, 19880, 0, 0, 2, 0, 1588.49, -1637.97, 17.1627, 0, 0, -178.7, 1588.49, -1637.97, 12.2525, 0, 0, -178.7),
(13, 968, 0, 0, 2, 0, 1544.7, -1630.74, 13.0527, 0, 89.5999, 90.1, 1544.7, -1630.74, 13.0527, 0, 0, 91.1999),
(17, 975, 0, 0, -1, 0, 1145.43, -1290.97, 14.2359, 0, 0, 179.487, 1136.48, -1290.89, 14.2359, 0, 0, 179.487),
(18, 11714, 6, 24518, 2, 0, 250.464, 63.2729, 1003.81, 0, 0, -179.838, 250.471, 60.913, 1003.81, 0, 0, -179.838),
(19, 11714, 6, 24518, 2, 0, 246.37, 72.4204, 1003.87, 0, 0, -89.9036, 248.82, 72.4244, 1003.87, 0, 0, -89.9036);

-- --------------------------------------------------------

--
-- Table structure for table `inventory`
--

CREATE TABLE `inventory` (
  `ID` int(12) DEFAULT 0,
  `invID` int(12) NOT NULL,
  `invItem` varchar(32) DEFAULT NULL,
  `invModel` int(12) DEFAULT 0,
  `invQuantity` int(12) DEFAULT 0,
  `invType` int(12) DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `inventory`
--

INSERT INTO `inventory` (`ID`, `invID`, `invItem`, `invModel`, `invQuantity`, `invType`) VALUES
(1, 772, 'Colt 45', 346, 1, 0),
(1, 774, 'Chainsaw', 341, 1, 0),
(1, 778, 'Knife', 335, 1, 0);

-- --------------------------------------------------------

--
-- Table structure for table `kick_logs`
--

CREATE TABLE `kick_logs` (
  `id` int(11) NOT NULL,
  `KickedDBID` int(11) NOT NULL,
  `KickedName` varchar(32) NOT NULL,
  `Reason` varchar(128) NOT NULL,
  `KickedBy` varchar(32) NOT NULL,
  `Date` varchar(90) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Table structure for table `logs`
--

CREATE TABLE `logs` (
  `type` varchar(512) NOT NULL DEFAULT 'none',
  `name` varchar(512) NOT NULL DEFAULT 'none',
  `result` varchar(512) NOT NULL DEFAULT 'none',
  `ID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `logs`
--

INSERT INTO `logs` (`type`, `name`, `result`, `ID`) VALUES
('Logs Advertise', 'Jayvon Williams', '[SELL] Sultan bet', 0);

-- --------------------------------------------------------

--
-- Table structure for table `masters`
--

CREATE TABLE `masters` (
  `acc_dbid` int(11) NOT NULL,
  `acc_name` varchar(32) NOT NULL DEFAULT 'None',
  `acc_pass` varchar(128) NOT NULL DEFAULT 'None',
  `secret_word` int(11) NOT NULL DEFAULT 0,
  `forum_name` varchar(60) NOT NULL DEFAULT 'Null',
  `register_date` varchar(90) NOT NULL DEFAULT 'None',
  `register_ip` varchar(60) NOT NULL DEFAULT 'None',
  `active_ip` varchar(60) NOT NULL DEFAULT 'None',
  `verified` int(11) NOT NULL DEFAULT 0,
  `discord` varchar(128) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `masters`
--

INSERT INTO `masters` (`acc_dbid`, `acc_name`, `acc_pass`, `secret_word`, `forum_name`, `register_date`, `register_ip`, `active_ip`, `verified`, `discord`) VALUES
(18, 'Radeetz', '051bb6ea0a45dbf11e4bbce3c21141678b10be9d', 98765, 'Radeetz', 'February 12, 2024 19:46:10', '127.0.0.1', '127.0.0.1', 1, '706433548797607957'),
(60, 'Blixkyyy', '051bb6ea0a45dbf11e4bbce3c21141678b10be9d', 4865, 'None', 'May 2, 2024 13:04:40', '127.0.0.1', '127.0.0.1', 1, '0');

-- --------------------------------------------------------

--
-- Table structure for table `properties`
--

CREATE TABLE `properties` (
  `PropertyDBID` int(11) NOT NULL,
  `PropertyOwnerDBID` int(11) NOT NULL DEFAULT 0,
  `PropertyType` int(11) NOT NULL,
  `PropertyFaction` int(11) NOT NULL DEFAULT 0,
  `PropertyEntranceX` float NOT NULL DEFAULT 0,
  `PropertyEntranceY` float NOT NULL DEFAULT 0,
  `PropertyEntranceZ` float NOT NULL DEFAULT 0,
  `PropertyEntranceInterior` int(11) NOT NULL DEFAULT 0,
  `PropertyEntranceWorld` int(11) NOT NULL DEFAULT 0,
  `PropertyInteriorX` int(11) NOT NULL DEFAULT 0,
  `PropertyInteriorY` int(11) NOT NULL DEFAULT 0,
  `PropertyInteriorZ` int(11) NOT NULL DEFAULT 0,
  `PropertyInteriorIntID` int(11) NOT NULL DEFAULT 0,
  `PropertyInteriorWorld` int(11) NOT NULL DEFAULT 0,
  `PropertyMarketPrice` int(11) NOT NULL DEFAULT 1000,
  `PropertyLevel` int(11) NOT NULL DEFAULT 1,
  `PropertyLocked` tinyint(1) NOT NULL DEFAULT 0,
  `PropertyCashbox` int(11) NOT NULL DEFAULT 0,
  `PropertyAddress` varchar(128) NOT NULL DEFAULT 'None'
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `properties`
--

INSERT INTO `properties` (`PropertyDBID`, `PropertyOwnerDBID`, `PropertyType`, `PropertyFaction`, `PropertyEntranceX`, `PropertyEntranceY`, `PropertyEntranceZ`, `PropertyEntranceInterior`, `PropertyEntranceWorld`, `PropertyInteriorX`, `PropertyInteriorY`, `PropertyInteriorZ`, `PropertyInteriorIntID`, `PropertyInteriorWorld`, `PropertyMarketPrice`, `PropertyLevel`, `PropertyLocked`, `PropertyCashbox`, `PropertyAddress`) VALUES
(42, 1, 3, 0, 2065.1, -1703.42, 14.1484, 0, 0, 330, 462, 998, 8, 38926, 8000000, 0, 0, 0, '1th 107TH Street');

-- --------------------------------------------------------

--
-- Table structure for table `propertiesstorage`
--

CREATE TABLE `propertiesstorage` (
  `ID` int(11) NOT NULL DEFAULT 0,
  `itemID` int(11) NOT NULL,
  `itemModel` int(11) NOT NULL DEFAULT 0,
  `itemName` varchar(128) NOT NULL DEFAULT 'none',
  `itemQuantity` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `relations`
--

CREATE TABLE `relations` (
  `ID` int(11) NOT NULL,
  `RelationsID` int(11) NOT NULL DEFAULT 0,
  `BusinessID` int(11) NOT NULL DEFAULT 0,
  `RelationsPoints` int(11) NOT NULL DEFAULT 0,
  `RelationsBusinessName` varchar(90) NOT NULL DEFAULT 'none'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `relations`
--

INSERT INTO `relations` (`ID`, `RelationsID`, `BusinessID`, `RelationsPoints`, `RelationsBusinessName`) VALUES
(1, 9, 47, 100, 'Pawnstore Plaza'),
(2, 1, 47, 0, 'Pawnstore Plaza'),
(3, 34, 64, 100, '');

-- --------------------------------------------------------

--
-- Table structure for table `server_data`
--

CREATE TABLE `server_data` (
  `id` int(12) NOT NULL,
  `fish` int(11) NOT NULL DEFAULT 0,
  `fabric` int(11) NOT NULL DEFAULT 0,
  `steel` int(11) NOT NULL DEFAULT 0,
  `woods` int(11) NOT NULL DEFAULT 0,
  `foods` int(11) NOT NULL DEFAULT 0,
  `clothes` int(11) NOT NULL DEFAULT 0,
  `appliances` int(11) NOT NULL DEFAULT 0,
  `materials` int(11) NOT NULL DEFAULT 0,
  `drugs` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `server_data`
--

INSERT INTO `server_data` (`id`, `fish`, `fabric`, `steel`, `woods`, `foods`, `clothes`, `appliances`, `materials`, `drugs`) VALUES
(0, 50, 59, 36, 21, 20, 32, 20, 50, 20);

-- --------------------------------------------------------

--
-- Table structure for table `spawnables`
--

CREATE TABLE `spawnables` (
  `spawnablesID` int(11) NOT NULL,
  `spawnablesX` float NOT NULL DEFAULT 0,
  `spawnablesY` float NOT NULL DEFAULT 0,
  `spawnablesZ` float NOT NULL DEFAULT 0,
  `spawnablesRX` float NOT NULL DEFAULT 0,
  `spawnablesRY` float NOT NULL DEFAULT 0,
  `spawnablesRZ` float NOT NULL DEFAULT 0,
  `spawnablesInterior` int(11) NOT NULL DEFAULT 0,
  `spawnablesWorld` int(11) NOT NULL DEFAULT 0,
  `spawnablesObjectID` int(11) NOT NULL DEFAULT 0,
  `spawnablesType` int(11) NOT NULL DEFAULT 0,
  `spawnablesAmount` int(11) NOT NULL DEFAULT 0,
  `spawnablesOwner` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `spray_tags`
--

CREATE TABLE `spray_tags` (
  `id` int(11) UNSIGNED NOT NULL,
  `owner` int(11) NOT NULL DEFAULT 0,
  `vehicle` int(11) NOT NULL DEFAULT -1,
  `text` varchar(128) NOT NULL DEFAULT 'Exemplo',
  `models` int(11) NOT NULL DEFAULT 0,
  `type` int(11) NOT NULL DEFAULT 0,
  `font` varchar(128) NOT NULL DEFAULT 'Arial',
  `fontsize` int(11) NOT NULL DEFAULT 24,
  `bold` int(11) NOT NULL DEFAULT 0,
  `color` int(11) NOT NULL DEFAULT 0,
  `posx` varchar(32) DEFAULT '0.0',
  `posy` varchar(32) DEFAULT '0.0',
  `posz` varchar(32) DEFAULT '0.0',
  `posrx` varchar(32) DEFAULT '0.0',
  `posry` varchar(32) DEFAULT '0.0',
  `posrz` varchar(32) DEFAULT NULL,
  `vw` int(11) DEFAULT 0,
  `interior` int(11) DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

-- --------------------------------------------------------

--
-- Table structure for table `tickets`
--

CREATE TABLE `tickets` (
  `ID` int(11) NOT NULL DEFAULT 0,
  `DBID` int(11) NOT NULL DEFAULT 0,
  `Fee` int(11) NOT NULL DEFAULT 0,
  `Reason` varchar(64) NOT NULL DEFAULT 'None',
  `Date` varchar(36) NOT NULL DEFAULT 'None'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `toys`
--

CREATE TABLE `toys` (
  `Id` int(10) NOT NULL,
  `Owner` int(11) NOT NULL DEFAULT 0,
  `Slot0_Model` int(8) NOT NULL DEFAULT 0,
  `Slot0_Bone` int(8) NOT NULL DEFAULT 0,
  `Slot0_XPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_YPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_ZPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_XRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_YRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_ZRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_XScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_YScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_ZScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_Model` int(8) NOT NULL DEFAULT 0,
  `Slot1_Bone` int(8) NOT NULL DEFAULT 0,
  `Slot1_XPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_YPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_ZPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_XRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_YRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_ZRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_XScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_YScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot1_ZScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_Model` int(8) NOT NULL DEFAULT 0,
  `Slot2_Bone` int(8) NOT NULL DEFAULT 0,
  `Slot2_XPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_YPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_ZPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_XRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_YRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_ZRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_XScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_YScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot2_ZScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_Model` int(8) NOT NULL DEFAULT 0,
  `Slot3_Bone` int(8) NOT NULL DEFAULT 0,
  `Slot3_XPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_YPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_ZPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_XRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_YRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_ZRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_XScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_YScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot3_ZScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_Model` int(8) NOT NULL DEFAULT 0,
  `Slot4_Bone` int(8) NOT NULL DEFAULT 0,
  `Slot4_XPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_YPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_ZPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_XRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_YRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_ZRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_XScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_YScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot4_ZScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_Model` int(8) NOT NULL DEFAULT 0,
  `Slot5_Bone` int(8) NOT NULL DEFAULT 0,
  `Slot5_XPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_YPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_ZPos` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_XRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_YRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_ZRot` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_XScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_YScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot5_ZScale` float(20,3) NOT NULL DEFAULT 0.000,
  `Slot0_Toggle` int(3) NOT NULL DEFAULT 0,
  `Slot1_Toggle` int(3) NOT NULL DEFAULT 0,
  `Slot2_Toggle` int(3) NOT NULL DEFAULT 0,
  `Slot3_Toggle` int(3) NOT NULL DEFAULT 0,
  `Slot4_Toggle` int(3) NOT NULL DEFAULT 0,
  `Slot0_Type` int(11) NOT NULL DEFAULT 0,
  `Slot1_Type` int(11) NOT NULL DEFAULT 0,
  `Slot2_Type` int(11) NOT NULL DEFAULT 0,
  `Slot3_Type` int(11) NOT NULL DEFAULT 0
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `toys`
--

INSERT INTO `toys` (`Id`, `Owner`, `Slot0_Model`, `Slot0_Bone`, `Slot0_XPos`, `Slot0_YPos`, `Slot0_ZPos`, `Slot0_XRot`, `Slot0_YRot`, `Slot0_ZRot`, `Slot0_XScale`, `Slot0_YScale`, `Slot0_ZScale`, `Slot1_Model`, `Slot1_Bone`, `Slot1_XPos`, `Slot1_YPos`, `Slot1_ZPos`, `Slot1_XRot`, `Slot1_YRot`, `Slot1_ZRot`, `Slot1_XScale`, `Slot1_YScale`, `Slot1_ZScale`, `Slot2_Model`, `Slot2_Bone`, `Slot2_XPos`, `Slot2_YPos`, `Slot2_ZPos`, `Slot2_XRot`, `Slot2_YRot`, `Slot2_ZRot`, `Slot2_XScale`, `Slot2_YScale`, `Slot2_ZScale`, `Slot3_Model`, `Slot3_Bone`, `Slot3_XPos`, `Slot3_YPos`, `Slot3_ZPos`, `Slot3_XRot`, `Slot3_YRot`, `Slot3_ZRot`, `Slot3_XScale`, `Slot3_YScale`, `Slot3_ZScale`, `Slot4_Model`, `Slot4_Bone`, `Slot4_XPos`, `Slot4_YPos`, `Slot4_ZPos`, `Slot4_XRot`, `Slot4_YRot`, `Slot4_ZRot`, `Slot4_XScale`, `Slot4_YScale`, `Slot4_ZScale`, `Slot5_Model`, `Slot5_Bone`, `Slot5_XPos`, `Slot5_YPos`, `Slot5_ZPos`, `Slot5_XRot`, `Slot5_YRot`, `Slot5_ZRot`, `Slot5_XScale`, `Slot5_YScale`, `Slot5_ZScale`, `Slot0_Toggle`, `Slot1_Toggle`, `Slot2_Toggle`, `Slot3_Toggle`, `Slot4_Toggle`, `Slot0_Type`, `Slot1_Type`, `Slot2_Type`, `Slot3_Type`) VALUES
(18, 11, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(17, 9, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(16, 10, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(15, 1, 0, 2, 0.121, 0.000, 0.011, 0.000, 0.000, 0.000, 1.555, 0.948, 1.000, 0, 2, 0.114, 0.069, -0.004, -62.600, 89.500, 150.000, 0.842, 1.023, 1.263, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(19, 12, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(20, 13, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(21, 14, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(22, 15, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(23, 16, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(24, 17, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(25, 18, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(26, 19, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(27, 20, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(28, 21, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(29, 22, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(30, 23, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(31, 24, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(32, 26, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(33, 28, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(34, 31, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(35, 32, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(36, 33, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(37, 29, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(38, 34, 18640, 2, 0.067, 0.000, 0.000, 0.000, 0.000, 0.000, 1.000, 1.000, 1.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(39, 35, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(40, 36, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(41, 37, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(42, 38, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(43, 39, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(44, 40, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(45, 43, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(46, 44, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(47, 45, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(48, 46, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(49, 49, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(50, 50, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(51, 51, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(52, 52, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(53, 53, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(54, 56, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(55, 57, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0, 0, 0, 0, 0, 0, 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `trashcan`
--

CREATE TABLE `trashcan` (
  `id` int(11) NOT NULL,
  `value` int(11) NOT NULL DEFAULT 0,
  `posx` float NOT NULL,
  `posy` float NOT NULL,
  `posz` float NOT NULL,
  `posrx` float NOT NULL,
  `posry` float NOT NULL,
  `posrz` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `trashcan`
--

INSERT INTO `trashcan` (`id`, `value`, `posx`, `posy`, `posz`, `posrx`, `posry`, `posrz`) VALUES
(4, 0, 2018.16, -1741.9, 12.9669, 0, 0, 0),
(5, 0, 2044.91, -1701.68, 13.0412, 0, 0, 0),
(6, 0, 2056.27, -1780.42, 13.0171, 0, 0, 0),
(7, 0, 2093.16, -1789.03, 12.8855, 0, 0, 0),
(8, 0, 2108.35, -1885.34, 13.0189, 0, 0, 0),
(9, 0, 2228.08, -1883.67, 13.0228, 0, 0, 0),
(10, 0, 1213.76, -1121.47, 25.0156, 0, 0, 0),
(11, 0, 1518.72, -1604.78, 13.036, 0, 0, 0),
(12, 0, 1565.4, -1580.83, 13.0186, 0, 0, 0),
(13, 0, 1883.71, -1606.73, 13.0145, 0, 0, 0),
(14, 0, 2045.82, -1640.53, 13.0216, 0, 0, 0),
(15, 0, 2225.31, -1409.77, 23.4735, 0, 0, 0),
(16, 0, 2101.34, -1263.49, 23.4618, 0, 0, 0),
(17, 0, 2497.86, -1514.6, 23.459, 0, 0, 0),
(18, 0, 2483, -1717.93, 13.0188, 0, 0, 0),
(19, 0, 2325.91, -1758.57, 13.0027, 0, 0, 0),
(20, 0, 1892.64, -2096.25, 12.9476, 0, 0, 0),
(21, 0, 1929.67, -2028.59, 13.018, 0, 0, 0),
(22, 0, 1627.39, -1862.66, 13.0099, 0, 0, 0),
(23, 0, 1459.77, -1862.26, 13.0174, 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `tree`
--

CREATE TABLE `tree` (
  `id` int(11) NOT NULL,
  `posx` float NOT NULL DEFAULT 0,
  `posy` float NOT NULL DEFAULT 0,
  `posz` float NOT NULL DEFAULT 0,
  `posrx` float NOT NULL DEFAULT 0,
  `posry` float NOT NULL DEFAULT 0,
  `posrz` float NOT NULL DEFAULT 0,
  `time` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `tree`
--

INSERT INTO `tree` (`id`, `posx`, `posy`, `posz`, `posrx`, `posry`, `posrz`, `time`) VALUES
(1, -1275.46, -1463.03, 103.33, 0, 0, 336.66, 0),
(2, -655.291, -1217.52, 23.9903, 0, 0, 20.517, 0),
(3, -607.704, -1426.91, 13.9335, 0, 0, 185.812, 0),
(4, -594.379, -1560.64, 11.3064, 0, 0, 282.577, 0),
(5, -554.959, -1578.05, 7.12028, 0, 0, 282.503, 0),
(6, -554.475, -1529.97, 8.11248, 0, 0, 24.4885, 0),
(7, -600.535, -884.585, 105.698, 0, 0, 311.916, 0),
(8, -1267.13, -1464.79, 103.757, 0, 0, 266.549, 0),
(9, -1260.45, -1465.9, 103.997, 0, 0, 273.535, 0),
(10, -1268.36, -1448.3, 104.568, 0, 0, 1.32987, 0),
(11, -1272.18, -1439.5, 104.914, 0, 0, 85.0793, 0),
(12, -1069.55, -1727.9, 75.4672, 0, 0, 355.816, 0),
(13, -1091.72, -1715.5, 75.4172, 0, 0, 77.4329, 0),
(14, -993.998, -1326.76, 136.929, 0, 0, 157.656, 0),
(15, -1088.33, -1318.77, 128.31, 0, 0, 83.8325, 0),
(16, -460.239, -691.521, 18.9669, 5.9, 0, 157.215, 0),
(17, -808.493, -423.643, 13.995, 0, 0, 150.008, 0);

-- --------------------------------------------------------

--
-- Table structure for table `vehicles`
--

CREATE TABLE `vehicles` (
  `VehicleDBID` int(11) NOT NULL,
  `VehicleOwnerDBID` int(11) NOT NULL,
  `VehicleFaction` int(11) NOT NULL DEFAULT 0,
  `VehicleModel` int(11) NOT NULL DEFAULT 0,
  `VehicleColor1` int(11) NOT NULL DEFAULT 0,
  `VehicleColor2` int(11) NOT NULL DEFAULT 0,
  `VehiclePaintjob` int(11) NOT NULL DEFAULT -1,
  `VehicleParkPosX` float NOT NULL DEFAULT 0,
  `VehicleParkPosY` float NOT NULL DEFAULT 0,
  `VehicleParkPosZ` float NOT NULL DEFAULT 0,
  `VehicleParkPosA` float NOT NULL DEFAULT 0,
  `VehicleParkInterior` int(11) NOT NULL DEFAULT 0,
  `VehicleParkWorld` int(11) NOT NULL DEFAULT 0,
  `VehiclePlates` varchar(32) NOT NULL DEFAULT 'None',
  `VehicleFakePlates` varchar(32) NOT NULL DEFAULT 'None',
  `VehiclePlatesStatus` tinyint(1) NOT NULL DEFAULT 0,
  `VehiclePlatesFake` tinyint(1) NOT NULL DEFAULT 0,
  `VehicleLocked` int(11) NOT NULL DEFAULT 0,
  `VehicleRental` tinyint(1) NOT NULL DEFAULT 0,
  `VehicleRentalTimer` int(11) NOT NULL DEFAULT 0,
  `VehicleImpounded` tinyint(1) NOT NULL DEFAULT 0,
  `VehicleImpoundPosX` float NOT NULL DEFAULT 0,
  `VehicleImpoundPosY` float NOT NULL DEFAULT 0,
  `VehicleImpoundPosZ` float NOT NULL DEFAULT 0,
  `VehicleImpoundPosA` float NOT NULL DEFAULT 0,
  `VehicleSirens` int(11) NOT NULL DEFAULT 0,
  `VehicleFuel` float NOT NULL DEFAULT 100,
  `VehicleMiles` int(11) NOT NULL DEFAULT 0,
  `VehicleLastDrivers1` int(11) NOT NULL DEFAULT 0,
  `VehicleLastDrivers2` int(11) NOT NULL DEFAULT 0,
  `VehicleLastDrivers3` int(11) NOT NULL DEFAULT 0,
  `VehicleLastDrivers4` int(11) NOT NULL DEFAULT 0,
  `VehicleLastPassengers1` int(11) NOT NULL DEFAULT 0,
  `VehicleLastPassengers2` int(11) NOT NULL DEFAULT 0,
  `VehicleLastPassengers3` int(11) NOT NULL DEFAULT 0,
  `VehicleLastPassengers4` int(11) NOT NULL DEFAULT 0,
  `VehicleBattery` float NOT NULL DEFAULT 100,
  `VehicleEngine` float NOT NULL DEFAULT 100,
  `VehicleTimesDestroyed` int(11) NOT NULL DEFAULT 0,
  `VehicleXMR` tinyint(1) NOT NULL DEFAULT 0,
  `VehicleAlarmLevel` int(11) NOT NULL DEFAULT 0,
  `VehicleLockLevel` int(11) NOT NULL DEFAULT 0,
  `VehicleImmobLevel` int(11) NOT NULL DEFAULT 1,
  `VehicleHealth` float NOT NULL DEFAULT 1000,
  `VehicleBody` int(11) NOT NULL DEFAULT 0,
  `VehicleTire` int(11) NOT NULL DEFAULT 0,
  `VehicleMods0` int(11) NOT NULL DEFAULT 0,
  `VehicleMods1` int(11) NOT NULL DEFAULT 0,
  `VehicleMods2` int(11) NOT NULL DEFAULT 0,
  `VehicleMods3` int(11) NOT NULL DEFAULT 0,
  `VehicleMods4` int(11) NOT NULL DEFAULT 0,
  `VehicleMods5` int(11) NOT NULL DEFAULT 0,
  `VehicleMods6` int(11) NOT NULL DEFAULT 0,
  `VehicleMods7` int(11) NOT NULL DEFAULT 0,
  `VehicleMods8` int(11) NOT NULL DEFAULT 0,
  `VehicleMods9` int(11) NOT NULL DEFAULT 0,
  `VehicleMods10` int(11) NOT NULL DEFAULT 0,
  `VehicleMods11` int(11) NOT NULL DEFAULT 0,
  `VehicleMods12` int(11) NOT NULL DEFAULT 0,
  `VehicleMods13` int(11) NOT NULL DEFAULT 0,
  `VehicleMods14` int(11) NOT NULL DEFAULT 0,
  `VehicleMods15` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Dumping data for table `vehicles`
--

INSERT INTO `vehicles` (`VehicleDBID`, `VehicleOwnerDBID`, `VehicleFaction`, `VehicleModel`, `VehicleColor1`, `VehicleColor2`, `VehiclePaintjob`, `VehicleParkPosX`, `VehicleParkPosY`, `VehicleParkPosZ`, `VehicleParkPosA`, `VehicleParkInterior`, `VehicleParkWorld`, `VehiclePlates`, `VehicleFakePlates`, `VehiclePlatesStatus`, `VehiclePlatesFake`, `VehicleLocked`, `VehicleRental`, `VehicleRentalTimer`, `VehicleImpounded`, `VehicleImpoundPosX`, `VehicleImpoundPosY`, `VehicleImpoundPosZ`, `VehicleImpoundPosA`, `VehicleSirens`, `VehicleFuel`, `VehicleMiles`, `VehicleLastDrivers1`, `VehicleLastDrivers2`, `VehicleLastDrivers3`, `VehicleLastDrivers4`, `VehicleLastPassengers1`, `VehicleLastPassengers2`, `VehicleLastPassengers3`, `VehicleLastPassengers4`, `VehicleBattery`, `VehicleEngine`, `VehicleTimesDestroyed`, `VehicleXMR`, `VehicleAlarmLevel`, `VehicleLockLevel`, `VehicleImmobLevel`, `VehicleHealth`, `VehicleBody`, `VehicleTire`, `VehicleMods0`, `VehicleMods1`, `VehicleMods2`, `VehicleMods3`, `VehicleMods4`, `VehicleMods5`, `VehicleMods6`, `VehicleMods7`, `VehicleMods8`, `VehicleMods9`, `VehicleMods10`, `VehicleMods11`, `VehicleMods12`, `VehicleMods13`, `VehicleMods14`, `VehicleMods15`) VALUES
(88, 52, 0, 462, 0, 0, -1, 1659.28, -1731.72, 12.9811, 268.901, 0, 0, '7HJG46', 'None', 0, 0, 0, 1, 53, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 100, 0, 0, 0, 0, 1, 1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(94, 1, 0, 422, 1, 1, -1, 1520.4, -1838.77, 13.5211, 88.8226, 0, 0, 'None', 'None', 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 85, 30, 0, 0, 0, 0, 0, 0, 0, 0, 100, 100, 0, 0, 0, 0, 1, 963.681, 19988481, 0, 0, 0, 0, 1007, 1013, 0, 1021, 1076, 0, 0, 0, 0, 0, 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `vstorage`
--

CREATE TABLE `vstorage` (
  `ID` int(11) NOT NULL DEFAULT 0,
  `itemID` int(11) NOT NULL,
  `itemModel` int(11) NOT NULL DEFAULT 0,
  `itemQuantity` int(11) NOT NULL DEFAULT 0,
  `itemName` varchar(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci DEFAULT NULL,
  `type` int(11) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `ajail_logs`
--
ALTER TABLE `ajail_logs`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `bannedlist`
--
ALTER TABLE `bannedlist`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `ban_logs`
--
ALTER TABLE `ban_logs`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `businesses`
--
ALTER TABLE `businesses`
  ADD PRIMARY KEY (`BusinessDBID`);

--
-- Indexes for table `characters`
--
ALTER TABLE `characters`
  ADD PRIMARY KEY (`char_dbid`);

--
-- Indexes for table `contacts`
--
ALTER TABLE `contacts`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `court`
--
ALTER TABLE `court`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `criminal_record`
--
ALTER TABLE `criminal_record`
  ADD PRIMARY KEY (`idx`);

--
-- Indexes for table `dropped`
--
ALTER TABLE `dropped`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `entrance`
--
ALTER TABLE `entrance`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `factions`
--
ALTER TABLE `factions`
  ADD PRIMARY KEY (`DBID`);

--
-- Indexes for table `faction_ranks`
--
ALTER TABLE `faction_ranks`
  ADD PRIMARY KEY (`factionid`),
  ADD UNIQUE KEY `factionid` (`factionid`);

--
-- Indexes for table `furniture`
--
ALTER TABLE `furniture`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `gates`
--
ALTER TABLE `gates`
  ADD PRIMARY KEY (`dbid`);

--
-- Indexes for table `inventory`
--
ALTER TABLE `inventory`
  ADD PRIMARY KEY (`invID`);

--
-- Indexes for table `kick_logs`
--
ALTER TABLE `kick_logs`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `logs`
--
ALTER TABLE `logs`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `masters`
--
ALTER TABLE `masters`
  ADD PRIMARY KEY (`acc_dbid`);

--
-- Indexes for table `properties`
--
ALTER TABLE `properties`
  ADD PRIMARY KEY (`PropertyDBID`);

--
-- Indexes for table `propertiesstorage`
--
ALTER TABLE `propertiesstorage`
  ADD PRIMARY KEY (`itemID`);

--
-- Indexes for table `relations`
--
ALTER TABLE `relations`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `server_data`
--
ALTER TABLE `server_data`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `spawnables`
--
ALTER TABLE `spawnables`
  ADD PRIMARY KEY (`spawnablesID`);

--
-- Indexes for table `spray_tags`
--
ALTER TABLE `spray_tags`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `tickets`
--
ALTER TABLE `tickets`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `toys`
--
ALTER TABLE `toys`
  ADD PRIMARY KEY (`Id`),
  ADD UNIQUE KEY `id` (`Owner`);

--
-- Indexes for table `trashcan`
--
ALTER TABLE `trashcan`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `tree`
--
ALTER TABLE `tree`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `vehicles`
--
ALTER TABLE `vehicles`
  ADD PRIMARY KEY (`VehicleDBID`);

--
-- Indexes for table `vstorage`
--
ALTER TABLE `vstorage`
  ADD PRIMARY KEY (`itemID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `ajail_logs`
--
ALTER TABLE `ajail_logs`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=19;

--
-- AUTO_INCREMENT for table `bannedlist`
--
ALTER TABLE `bannedlist`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `ban_logs`
--
ALTER TABLE `ban_logs`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `businesses`
--
ALTER TABLE `businesses`
  MODIFY `BusinessDBID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=22;

--
-- AUTO_INCREMENT for table `characters`
--
ALTER TABLE `characters`
  MODIFY `char_dbid` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=58;

--
-- AUTO_INCREMENT for table `court`
--
ALTER TABLE `court`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- AUTO_INCREMENT for table `criminal_record`
--
ALTER TABLE `criminal_record`
  MODIFY `idx` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=25;

--
-- AUTO_INCREMENT for table `dropped`
--
ALTER TABLE `dropped`
  MODIFY `ID` int(12) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=170;

--
-- AUTO_INCREMENT for table `entrance`
--
ALTER TABLE `entrance`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT for table `factions`
--
ALTER TABLE `factions`
  MODIFY `DBID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=16;

--
-- AUTO_INCREMENT for table `faction_ranks`
--
ALTER TABLE `faction_ranks`
  MODIFY `factionid` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=16;

--
-- AUTO_INCREMENT for table `furniture`
--
ALTER TABLE `furniture`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=93;

--
-- AUTO_INCREMENT for table `gates`
--
ALTER TABLE `gates`
  MODIFY `dbid` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=20;

--
-- AUTO_INCREMENT for table `inventory`
--
ALTER TABLE `inventory`
  MODIFY `invID` int(12) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=784;

--
-- AUTO_INCREMENT for table `kick_logs`
--
ALTER TABLE `kick_logs`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT for table `masters`
--
ALTER TABLE `masters`
  MODIFY `acc_dbid` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=111;

--
-- AUTO_INCREMENT for table `properties`
--
ALTER TABLE `properties`
  MODIFY `PropertyDBID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=43;

--
-- AUTO_INCREMENT for table `propertiesstorage`
--
ALTER TABLE `propertiesstorage`
  MODIFY `itemID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT for table `relations`
--
ALTER TABLE `relations`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT for table `server_data`
--
ALTER TABLE `server_data`
  MODIFY `id` int(12) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `spawnables`
--
ALTER TABLE `spawnables`
  MODIFY `spawnablesID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- AUTO_INCREMENT for table `spray_tags`
--
ALTER TABLE `spray_tags`
  MODIFY `id` int(11) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=263;

--
-- AUTO_INCREMENT for table `toys`
--
ALTER TABLE `toys`
  MODIFY `Id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=56;

--
-- AUTO_INCREMENT for table `trashcan`
--
ALTER TABLE `trashcan`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=24;

--
-- AUTO_INCREMENT for table `tree`
--
ALTER TABLE `tree`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=18;

--
-- AUTO_INCREMENT for table `vehicles`
--
ALTER TABLE `vehicles`
  MODIFY `VehicleDBID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=95;

--
-- AUTO_INCREMENT for table `vstorage`
--
ALTER TABLE `vstorage`
  MODIFY `itemID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=70;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
